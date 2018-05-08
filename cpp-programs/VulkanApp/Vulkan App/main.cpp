// Basic didactic Vulkan application with comments explaining everything. Adapted from vulkan-tutorial.com

// Steps to draw triangle:
//
// 1. Create a VkInstance
// 2. Select a supported graphics card(VkPhysicalDevice)
// 3. Create a VkDevice and VkQueue for drawing and presentation
// 4. Create a window, window surface and swap chain
// 5. Wrap the swap chain images into VkImageView
// 6. Create a render pass that specifies the render targets and usage
// 7. Create framebuffers for the render pass
// 8. Set up the graphics pipeline
// 9. Allocate and record a command buffer with the draw commands for every possible swap chain image
// 10. Draw frames by acquiring images, submitting the right draw command buffer and returning the images back to the swap chain

// Functions have a lower case vk prefix, types like enumerations and structs have a Vk prefix and enumeration values have a VK_ prefix.

// Vulkan objects are either created directly with functions like vkCreateXXX, or allocated through another object with functions like vkAllocateXXX. The XXX are any 3 letters and they indicate the name of the Vulkan extension with the fn. After making sure that an object is no longer used anywhere, you need to destroy it with the counterparts vkDestroyXXX and vkFreeXXX. The parameters for these functions generally vary for different types of objects, but there is one parameter that they all share: pAllocator. This is an optional parameter that allows you to specify callbacks for a custom memory allocator. We will ignore this parameter in the tutorial and always pass nullptr as argument.

// Vulkan does not have the concept of a "default framebuffer", hence it requires an infrastructure that will own the buffers we will render to before we visualize them on the screen. This infrastructure is known as the swap chain and must be created explicitly in Vulkan. The swap chain is essentially a queue of images that are waiting to be presented to the screen. Our application will acquire such an image to draw to it, and then return it to the queue. How exactly the queue works and the conditions for presenting an image from the queue depend on how the swap chain is set up, but the general purpose of the swap chain is to synchronize the presentation of images with the refresh rate of the screen.

// A shader is a program designed to run on some stage of a graphics processor. Its purpose is to execute one of the programmable stages of the rendering pipeline.

// The graphics pipeline is the sequence of operations that take the vertices and textures of your meshes all the way to the pixels in the render targets. Vertex/index buffer > input assembler (collects the raw vertex data from the buffers) > vertex shader (run for every vertex, applies transformations to turn vertex positions from model space to screen space) > tessellation shaders (subdivide geometry based on certain rules to increase the mesh quality) > geoetry shader (run on every primitive (triangle, line, point) and can discard it or output more primitives than came in. Only useful on Intel's integrated (aot. dedicated) GPUs) > rasterization (discretizes the primitives into fragments. These are the pixel elements that they fill on the framebuffer. Any fragments that fall outside the screen are discarded) > fragment shader (invoked for every fragment that survives and determines which framebuffer(s) the fragments are written to and with which color and depth values) > color blending (mixes different fragments that map to the same pixel in the framebuffer. Fragments can simply overwrite each other, add up or be mixed based upon transparency.) > framebuffer. Many of these stages are programmable, so you can run your own code on GPU cores. In older APIs, after creating the pipeline you can easily modify it. In Vulkan, it is immutable, and you need to create a separate pipeline with every combination of states you want to use in rendering operations. But since each pipeline is fixed the driver can do some optimizations. Unlike earlier APIs, shader code in Vulkan has to be specified in a bytecode format as opposed to human-readable syntax. This bytecode format is called SPIR-V (spir 5).  It is a format that can be used to write graphics and compute shaders, but we will focus on shaders. The advantage of using a bytecode format is that the compilers written by GPU vendors to turn shader code into native code are significantly less complex. The past has shown that with human-readable syntax like GLSL, some GPU vendors were rather flexible with their interpretation of the standard. If you happen to write non-trivial shaders with a GPU from one of these vendors, then you'd risk other vendor's drivers rejecting your code. The LunarG SDK comes with glslangValidator.exe which compiles GLSL to SPIR-V. GLSL is a shading language with a C-style syntax. Programs written in it have a main function that is invoked for every object. Instead of using parameters for input and a return value as output, GLSL uses global variables to handle input and output. The language includes many features to aid in graphics programming, like built-in vector and matrix primitives. Functions for operations like cross products, matrix-vector products and reflections around a vector are included. The vector type is called vec with a number indicating the amount of elements. For example, a 3D position would be stored in a vec3. It is possible to access single components through members like .x, but it's also possible to create a new vector from multiple components at the same time. For example, the expression vec3(1.0, 2.0, 3.0).xy would result in vec2. The constructors of vectors can also take combinations of vector objects and scalar values. For example, a vec3 can be constructed with vec3(vec2(1.0, 2.0), 3.0). We will produce 2 SPIR-V binaries and load them into the program. A vertex shader produces the output of the vertices in *clip coordinates*. A clip coordinate is a four dimensional vector from the vertex shader that is subsequently turned into a normalized device coordinate by dividing the whole vector by its last component. These normalized device coordinates are homogeneous coordinates that map the framebuffer to a [-1, 1] by [-1, 1] coordinate system. It's like a square. -1, -1 is top left. 1, 1 is bottom right. The shape is inside. We can directly output normalized device coordinates by outputting them as clip coordinates from the vertex shader with the last component set to 1. That way the division to transform clip coordinates to normalized device coordinates will not change anything. Normally these coordinates would be stored in a vertex buffer.

// Commands in Vulkan, like drawing operations and memory transfers, are not executed directly using function calls. You have to record all of the operations you want to perform in command buffer objects.

// Buffers in Vulkan are regions of memory used for storing arbitrary data that can be read by the graphics card. They can be used to store vertex data, but they can also be used for many other purposes. Unlike other Vulkan objects, buffers do not automatically allocate memory for themselves so we need to do it.

// Drawing a rectangle takes two triangles, which means that we need a vertex buffer with 6 vertices. The problem is that the data of two vertices needs to be duplicated resulting in 50% redundancy. It only gets worse with more complex meshes, where vertices are reused in an average number of 3 triangles. The solution to this problem is to use an index buffer.

// Driver developers recommend that you store multiple buffers, like the vertex and index buffer, into a single VkBuffer and use offsets in commands like vkCmdBindVertexBuffers. The advantage is that your data is more cache friendly in that case, because it's closer together. It is even possible to reuse the same chunk of memory for multiple resources if they are not used during the same render operations, provided that their data is refreshed, of course. This is known as aliasing and some Vulkan functions have explicit flags to specify that you want to do this.

// 3D Graphics requires a model-view-projection (MVP) matrix. All 3 matrices need to be updated every frame to make an object spins. We could include it as vertex data, but that's a waste of memory and it would require us to update the vertex buffer whenever the transformation changes. The transformation could easily change every single frame. The right way to tackle this in Vulkan is to use resource descriptors. A descriptor is a way for shaders to freely access resources like buffers and images. We're going to set up a buffer that contains the transformation matrices and have the vertex shader access them through a descriptor. Usage of descriptors consists of three parts: 1. Specify a descriptor layout during pipeline creation 2. Allocate a descriptor set from a descriptor pool 3. Bind the descriptor set during rendering. The descriptor layout specifies the types of resources that are going to be accessed by the pipeline, just like a render pass specifies the types of attachments that will be accessed. A descriptor set specifies the actual buffer or image resources that will be bound to the descriptors, just like a framebuffer specifies the actual image views to bind to render pass attachments. The descriptor set is then bound for the drawing commands just like the vertex buffers and framebuffer. Uniform Buffer Objects (UBOs) are a type of descriptor.

// Model maps from an object's local coordinate space into world space, view from world space to camera space, projection from camera to screen. If you compose all three, you can use the one result to map all the way from object space to screen space.

//To color geometry using something beyond per-vertex colors, we need texture mapping. Adding a texture to our application will involve the following steps: 1. Create an image object backed by device memory 2. Fill it with pixels from an image file 3. Create an image sampler 4. Add a combined image sampler descriptor to sample colors from the texture. We'll start by creating a staging resource and filling it with pixel data and then we copy this to the final image object that we'll use for rendering. Although it is possible to create a staging image for this purpose, Vulkan also allows you to copy pixels from a VkBuffer to an image and the API for this is actually faster on some hardware. We'll first create this buffer and fill it with pixel values, and then we'll create an image to copy the pixels to.

// Images can have different layouts that affect how the pixels are organized in memory. Due to the way graphics hardware works, simply storing the pixels row by row may not lead to the best performance, for example. When performing any operation on images, you must make sure that they have the layout that is optimal for use in that operation. One of the most common ways to transition the layout of an image is a pipeline barrier. Pipeline barriers are primarily used for synchronizing access to resources, like making sure that an image was written to before it is read, but they can also be used to transition layouts. Barriers can additionally be used to transfer queue family ownership when using VK_SHARING_MODE_EXCLUSIVE. The layouts:
// VK_IMAGE_LAYOUT_PRESENT_SRC_KHR: Optimal for presentation
// VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL: Optimal as attachment for writing colors from the fragment shader
// VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL : Optimal as source in a transfer operation, like vkCmdCopyImageToBuffer
// VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL : Optimal as destination in a transfer operation, like vkCmdCopyBufferToImage
// VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL : Optimal for sampling from a shader

//#include <vulkan/vulkan.h>		// The Vulkan header from the LunarG SDK, which provides the functions, structures and enumerations.

#define GLFW_INCLUDE_VULKAN		// GLFW will include its own definition and load Vulkan.
#define GLM_FORCE_RADIANS		// The GLM_FORCE_RADIANS definition is necessary to make sure that functions like glm::rotate use radians as arguments
#define GLM_FORCE_DEPTH_ZERO_TO_ONE	// The depth range in Vulkan is 0.0 to 1.0 aot -1.0 to 1.0 in OpenGL
#define GLM_ENABLE_EXPERIMENTAL
#define STB_IMAGE_IMPLEMENTATION	// The header only defines the prototypes of the functions by default. One code file needs to include the header with the STB_IMAGE_IMPLEMENTATION definition to include the function bodies, otherwise we'll get linking errors.
#define TINYOBJLOADER_IMPLEMENTATION	// Includes function bodies and avoids linker errors
#include <tiny_obj_loader.h>	// The tinyobjloader library for loading .obj models
#include <stb_image.h>			// The stb image library (external)	used to load images
#include <GLFW/glfw3.h>			// The slash is for the subfolder.
#include <vector>
#include <iostream>				// Used to define errors
#include <stdexcept>			// Defines logic_error, domain_error, invalid_argument, length_error, out_of_range, runtime_error, range_error, overflow_error, underflow_error (arithmetic underflow: a number that is too small to be represented in the device meant to store it).
#include <functional>			// Std lib for hash functions and lambda functions (will be used for resource management)
#include <set>
#include <algorithm>			// For max and min
#include <fstream>
#include <glm/gtc/matrix_transform.hpp>	// The glm/gtc/matrix_transform.hpp header exposes functions that can be used to generate model transformations like glm::rotate, view transformations like glm::lookAt and projection transformations like glm::perspective.
#include <glm/glm.hpp>			// GLM = OpenGL Math, For vectors and matrices
#include <glm/gtx/hash.hpp>
#include <chrono>				// The chrono standard library header exposes functions to do precise timekeeping. We'll use this to make sure that the geometry rotates pi/2 degrees per sec.
#include <array>				// std::array is just a class (C++) version of the classic C array.That means its size is fixed at compile time and it will be allocated as a single chunk(e.g.taking space on the stack).The advantage it has is slightly better performance. std::vector is a small class containing pointers into the heap. (So when you allocate a std::vector, it always calls new.) They are slightly slower to access because those pointers have to be chased to get to the arrayed data. Since <array> is stored in the stack, it's considered bad practice to use it for large arrays. So it's used for small arrays that need to be created/destroyed/accessed a lot.
#include <unordered_map>		// Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order. map containers are generally slower than unordered_map containers to access individual elements by their key, but they allow the direct iteration on subsets based on their order. Internally, the elements in the unordered_map are not sorted in any particular order with respect to either their key or mapped values, but organized into buckets depending on their hash values to allow for fast access to individual elements directly by their key values (with a constant average time complexity on average).

// A proxy fn which handles looking up the address of vkCreateDebugReportCallbackEXT(). We need to look up its address because its an extension function so it's not automatically loaded.
// Another option is to have this as a static fn inside the class.
VkResult CreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback) {
	auto func = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");	// vkGetInstanceProcAddr() is what looks up the address
	if (func != nullptr)
		return func(instance, pCreateInfo, pAllocator, pCallback);
	else
		return VK_ERROR_EXTENSION_NOT_PRESENT;
}

// Similarly, vkDestroyDebugReportCallbackEXT needs to be explicitly loaded.
void DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator) {
	auto func = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
	if (func != nullptr)
		func(instance, callback, pAllocator);
}

struct QueueFamilyIndices {
	int graphicsFamily = -1;	// -1 means a queue of this family was not found
	int presentFamily = -1;		// We have 2 different queues because potentially the queue families supporting drawing commands (actually rendering) and presentation (displaying) do not overlap. That's why we have 2 diff. queues.

	bool isComplete() {
		return graphicsFamily >= 0 && presentFamily >= 0;
	}
};

// Just checking if a swap chain is available is not sufficient, because it may not actually be compatible with our window surface. Creating a swap chain also involves a lot more settings so we need to query for more details. This struct is used to pass swap chain details around once they've been queried:
struct SwapChainSupportDetails {
	VkSurfaceCapabilitiesKHR capabilities;		// Surface capabilities (min/max number of images in swap chain, min/max width and height of images)
	std::vector<VkSurfaceFormatKHR> formats;	// Surface formats (pixel format, color space)
	std::vector<VkPresentModeKHR> presentModes; // Available presentation modes
};

struct Vertex {	// For the vertex buffer for the vertex shader
	glm::vec3 pos;
	glm::vec3 color;
	glm::vec2 texCoord;	// Texture coordinates

	// First Vulkan struct needed to convey the data format to be passed to the vertex shader
	static VkVertexInputBindingDescription getBindingDescription() {
		// A vertex binding describes at which rate to load data from memory throughout the vertices. It specifies the number of bytes between data entries and whether to move to the next data entry after each vertex or after each instance.
		VkVertexInputBindingDescription bindingDescription = {};
		bindingDescription.binding = 0;	// Only 1 binding because we have only one array. 0 is the index of the binding.
		bindingDescription.stride = sizeof(Vertex);	// Number of bytes from one entry to the next
		bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;	// The other option is _INSTANCE for instanced rendering.

		return bindingDescription;
	}

	// Second Vulkan struct, describes how to handle vertex input.
	static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions() {
		std::array<VkVertexInputAttributeDescription, 3> attributeDescriptions = {};	// Note how the number of items in the array is specified as '2' in this format. An attribute description struct describes how to extract a vertex attribute from a chunk of vertex data originating from a binding description. We have two attributes, position and color, so we need two attribute description structs.
		attributeDescriptions[0].binding = 0;
		attributeDescriptions[0].location = 0;
		attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;	// The input in the vertex shader with index 0 is the position, which has two 32-bit float components.
		attributeDescriptions[0].offset = offsetof(Vertex, pos);

		attributeDescriptions[1].binding = 0;
		attributeDescriptions[1].location = 1;	// The index
		attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[1].offset = offsetof(Vertex, color);	// The offset from the beginning. The standard C++ macro offsetof expands to an integral constant expression of type std::size_t, the value of which is the offset, in bytes, from the beginning of an object of specified type to its specified member, including padding if any. offsetof throws no exceptions; the expression noexcept(offsetof(type, member)) always evaluates to true.

		attributeDescriptions[2].binding = 0;
		attributeDescriptions[2].location = 2;
		attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;	// Because it's a vec2 aot a vec3
		attributeDescriptions[2].offset = offsetof(Vertex, texCoord);

		return attributeDescriptions;
	}

	bool operator==(const Vertex& other) const {	// Necessary for using a vertex as an index in a map.
		return pos == other.pos && color == other.color && texCoord == other.texCoord;
	}
};

// Also necessary for using a custom type as an index in a map. It's a hash function for Vertex.
namespace std {
	template<> struct hash<Vertex> {	// We are using <glm/gtx/hash.hpp> The gtx folder is for experimental extensions, which is why we also used #define GLM_ENABLE_EXPERIMENTAL
		size_t operator()(Vertex const& vertex) const {
			return ((hash<glm::vec3>()(vertex.pos) ^ (hash<glm::vec3>()(vertex.color) << 1)) >> 1) ^ (hash<glm::vec2>()(vertex.texCoord) << 1);
		}
	};
}

struct UniformBufferObject {
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 proj;
};

//const std::vector<Vertex> vertices = {	// The vertices to draw. Because the position and colors are both in the same vector, it's called *interleaving* vertex attributes. The vertices represent the 4 corners of the rectangle and their colors.
//	{ { -0.5f, -0.5f, 0.0f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f } },	// top-left, red. The last pair fill the square with the texture from top left to top right
//	{ { 0.5f, -0.5f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f } },	// top-right, green
//	{ { 0.5f, 0.5f, 0.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f } },	// bottom-right, blue
//	{ { -0.5f, 0.5f, 0.0f }, { 1.0f, 1.0f, 1.0f }, { 1.0f, 1.0f } },	// bottom-left, white
//
//	{ { -0.5f, -0.5f, -0.5f },{ 1.0f, 0.0f, 0.0f },{ 0.0f, 0.0f } },
//	{ { 0.5f, -0.5f, -0.5f },{ 0.0f, 1.0f, 0.0f },{ 1.0f, 0.0f } },
//	{ { 0.5f, 0.5f, -0.5f },{ 0.0f, 0.0f, 1.0f },{ 1.0f, 1.0f } },
//	{ { -0.5f, 0.5f, -0.5f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 1.0f } }
//};
//
//const std::vector<uint16_t> indices = {	// It is possible to use either uint16_t or uint32_t for your index buffer depending on the number of entries in vertices. We can stick to uint16_t because we are using less than 56635 vertices.
//	0, 1, 2, 2, 3, 0,	// The vertices 0, 1, 2 constitute the first triangle. Then 2, 3, 0 for the second one to complete the rectangle.
//	4, 5, 6, 6, 7, 4
//};

class VulkanApp {	 // Vulkan objects will be stored as private class members.
public:
	void run() {
		initWindow();	// Initializes GLFW and creates a window
		initVulkan();	// Initiates Vulkan objects.
		mainLoop();		// Renders the frames.
		cleanup();		// Deallocating resources when the Window is closed. The resources are the Vulkan objects.
	}

private:
	const int WIDTH = 800;
	const int HEIGHT = 600;

	const std::string MODEL_PATH = "models/chalet.obj";
	const std::string TEXTURE_PATH = "textures/chalet.jpg";

	GLFWwindow * window;

	VkInstance instance;	// Holds the handle to the Vulkan instance created in createInstance()
	VkDebugReportCallbackEXT callback;	// The callback function

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE; // The graphics card we select will be stored here. This object will be implicitly destroyed when the VkInstance is destroyed, so we won't need to do anything new in the cleanup function.
	VkDevice device;	// After selecting the physical device we set up this logical device to interface with it.

	VkQueue graphicsQueue;	// Handle to the queues. Interfaces with the actual queues. Device queues are implicitly cleaned up when the device is destroyed, so we don't need to do anything in cleanup.
	VkQueue presentQueue;	// The presentation queue. Probably will end up being the same as graphicsQueue. Can check for that and implement better performance btw.

	VkSurfaceKHR surface;	// This is an object exposed by the VK_KHR_surface which is in our list of enabled extensions. The object represents an abstract type of surface to present rendered images to. The surface in our program will be backed by the window that we've already opened with GLFW.

	VkSwapchainKHR swapChain;
	std::vector<VkImage> swapChainImages;	// These are destroyed with the swap chain so no need to clean them up.
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;
	std::vector<VkImageView> swapChainImageViews;	// An image view is quite literally a view into an image. It describes how to access the image and which part of the image to access, for example if it should be treated as a 2D texture depth texture without any mipmapping levels.
	std::vector<VkFramebuffer> swapChainFramebuffers;

	VkRenderPass renderPass;
	VkDescriptorSetLayout descriptorSetLayout;	// All of the descriptor bindings are combined into a single VkDescriptorSetLayout object.
	VkDescriptorPool descriptorPool;
	VkDescriptorSet descriptorSet;
	VkPipelineLayout pipelineLayout;
	VkPipeline graphicsPipeline;

	VkCommandPool commandPool;	// We have to create a command pool before we can create command buffers. Command pools manage the memory that is used to store the buffers and command buffers are allocated from them
	std::vector<VkCommandBuffer> commandBuffers;	// Command buffers will be automatically freed when their command pool is destroyed, so no need to clean up.

	VkImage textureImage;
	VkDeviceMemory textureImageMemory;
	VkImageView textureImageView;
	VkSampler textureSampler;

	VkImage depthImage;
	VkDeviceMemory depthImageMemory;
	VkImageView depthImageView;

	VkSemaphore imageAvailableSemaphore; // Signals that an image has been acquired
	VkSemaphore renderFinishedSemaphore; // Signals that rendering has finished and presentation can happen

	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;	// We use uint32_t as opposed to uint16_t to support loading models with more than 65535 vertices.
	VkBuffer vertexBuffer;
	VkDeviceMemory vertexBufferMemory;
	VkBuffer indexBuffer;	// Just like the vertex data, the indices need to be uploaded into a VkBuffer for the GPU to be able to access them.
	VkDeviceMemory indexBufferMemory;
	VkBuffer uniformBuffer;	// A uniform is a global GLSL variable declared with the "uniform" storage qualifier. These act as parameters that the user of a shader program can pass to that program. We are using the descriptor set layout to work with our parameter. We need the uniform buffer as an interface between this program and the GLSL program.
	VkDeviceMemory uniformBufferMemory;

	const std::vector<const char*> validationLayers = {		// Lists required validation layers
		"VK_LAYER_LUNARG_standard_validation"
	};
	const std::vector<const char*> deviceExtensions = {		// Lists required device extensions.
		VK_KHR_SWAPCHAIN_EXTENSION_NAME		// This macro is defined as VK_KHR_swapchain which has to be enabled after querying for its support. The extension is not part of the Vulkan core. Also we need to check for swap chain support cuz not all graphics cards can present images on a screen eg. those for servers.
	};

#ifdef NDEBUG		// The NDEBUG macro is part of the C++ standard and means "not debug".
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

	static std::vector<char> readFile(const std::string& filename) {		// For the shaders
		std::ifstream file(filename, std::ios::ate | std::ios::binary);		// The readFile function will read all of the bytes from the specified file and return them in a byte array managed by std::vector. We start by opening the file with two flags: ate: Start reading at the end of the file, binary : Read the file as binary file(avoid text transformations). The advantage of starting to read at the end of the file is that we can use the read position to determine the size of the file and allocate a buffer.
		if (!file.is_open())
			throw std::runtime_error("Failed to open file!");
		size_t fileSize = (size_t)file.tellg(); // We get the file size because we read from the end.
		std::vector<char> buffer(fileSize);
		file.seekg(0); // We seek back to the beginning of the file and read all of the bytes at once:
		file.read(buffer.data(), fileSize);	// .data() for std::array or std::vector returns a pointer to the first element.
		file.close();
		return buffer;
	}

	bool checkValidationLayerSupport() {
		uint32_t layerCount;							// uint32_t is a fixed-width integer type along with many other ones introduced in C++11.
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);		// similar to vkEnumerateInstanceExtensionProperties() below

		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		// The actual checking:
		for (const char* layerName : validationLayers) {
			bool layerFound = false;

			for (const auto& layerProperties : availableLayers) {
				if (strcmp(layerName, layerProperties.layerName) == 0) {
					layerFound = true;
					break;
				}
			}

			if (!layerFound) {
				return false;
			}
		}

		return true;
	}

	std::vector<const char*> getRequiredExtensions() {	// Returns the list of required extensions (by GLFW) depending on whether validation layers are enabled or not.
		std::vector<const char*> extensions;

		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		for (uint32_t i = 0; i < glfwExtensionCount; i++) {
			extensions.push_back(glfwExtensions[i]);
		}

		if (enableValidationLayers) {
			extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);	// This is a macro for the VK_EXT_debug_report which extension allows the program (ie. the GLFW part) to receive the debug messages from the validation layers.
		}

		return extensions;
	}

	// We set up a callback to receive messages from validation layers using the VK_EXT_debug_report extension. So this method is called when there is a problem detected in the validation layer.
	// The VKAPI_ATTR and VKAPI_CALL ensure that the function has the right signature for Vulkan to call it.
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(		// The bold stuff are just #defined stuff.
		VkDebugReportFlagsEXT flags,	// Specifies the type of message, which can be a combination of any of the following bit flags: VK_DEBUG_REPORT_INFORMATION_BIT_EX, VK_DEBUG_REPORT_WARNING_BIT_EXT, VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT, VK_DEBUG_REPORT_ERROR_BIT_EXT, VK_DEBUG_REPORT_DEBUG_BIT_EXT.
		VkDebugReportObjectTypeEXT objType, // The objType parameter specifies the type of object that is the subject of the message. For example if obj below is a VkPhysicalDevice then objType would be VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT.
		uint64_t obj,
		size_t location,
		int32_t code,
		const char* layerPrefix,
		const char* msg,
		void* userData) {		// userData allows you to pass your own data to the callback.

		std::cerr << "Validation layer: " << msg << std::endl;

		return VK_FALSE;	// Hence the VkBool32 type.			The callback returns a boolean that indicates if the Vulkan call that triggered the validation layer message should be aborted. If the callback returns true, then the call is aborted with the VK_ERROR_VALIDATION_FAILED_EXT error. This is normally only used to test the validation layers themselves, so you should always return VK_FALSE.
	}

	static void onWindowResized(GLFWwindow* window, int width, int height) {	// Recreates swapchain
		if (width == 0 || height == 0) return;	// If size of window is non-zero (if window got minimized) we don't need to display anything.

		VulkanApp* app = reinterpret_cast<VulkanApp*>(glfwGetWindowUserPointer(window));
		app->recreateSwapChain();
	}

	void initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);	// Because GLFW was originally designed to create an OpenGL context, we need to tell it to not create an OpenGL context.
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);		// Not really necessary, windows are resizable by default.

		window = glfwCreateWindow(WIDTH, HEIGHT, "Hello Triangle with Vulkan", nullptr, nullptr);	// The fourth parameter allows you to optionally specify a monitor to open the window on and the last parameter is only relevant to OpenGL.

		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

		glfwSetWindowUserPointer(window, this);	// We need to create a pointer to window before we call the next function.
		glfwSetWindowSizeCallback(window, VulkanApp::onWindowResized);	// Specifies callback for the window resize event.
	}

	void createInstance() {	// The Vulkan instance is the connection between the app and the Vulkan library.
		if (enableValidationLayers && !checkValidationLayerSupport())
			throw std::runtime_error("Validation layers requested, but not available!");

		// Before creating the instance we need to fill this struct with info about the app. In Vulkan info is usually passed through structs:
		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;	// The first 4 bytes of any structure is sType ie. structure type. If there are newer structure types, they will be for eg. VK_STRUCTURE_TYPE_APPLICATION_INFO_2 for this one for eg.
		appInfo.pApplicationName = "Hello Triangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";					// Name of engine (if any) used to create the app. The docs say you should leave it as NULL if there's no engine.
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		// This next struct tells the Vulkan driver which global extensions and validation layers we want to use. Global here means that they apply to the entire program and not a specific device:
		VkInstanceCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		// We need to tell Vulkan through createInfo which extensions GLFW needs:
		auto extensions = getRequiredExtensions();
		createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		createInfo.ppEnabledExtensionNames = extensions.data();

		// Finally, global validation layers:
		if (enableValidationLayers) {
			createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
			createInfo.ppEnabledLayerNames = validationLayers.data();
		}
		else
			createInfo.enabledLayerCount = 0;

		//if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
		//	throw std::runtime_error("failed to create instance!");
		//}

		// Optional: Printing list of supported extensions:
		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);	// The fn is called just to get the extension count which is needed for the next line. Then, we call the function again using its full functionality.
		std::vector<VkExtensionProperties> supportedExtensions(extensionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, supportedExtensions.data());	// The first param is for filtering extensions, the last is for storing details of extensions which must be stored in this datatype.
		std::cout << "Available extensions:" << std::endl;
		for (const auto& extension : supportedExtensions)
			std::cout << "\t" << extension.extensionName << std::endl;

		// Optional: Displaying GLFW required extensions to check if all extensions needed by GLFW are included in the supported extension list:
		std::cout << std::endl << "GLFW required extensions:" << std::endl;
		for (auto i = 0; i < extensions.size(); ++i)		// I use auto instead of int because glfwExtensionCount is not really an int. It still gives a warning about unsigned/signed mismatch though.
			std::cout << "\t" << extensions.data()[i] << std::endl;

		VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);	// The second pointer is a pointer to custom allocator callbacks.
	}

	void setupDebugCallback() {
		if (!enableValidationLayers)
			return;
		VkDebugReportCallbackCreateInfoEXT createInfo = {};		// Struct with callback details.  Should be passed to the vkCreateDebugReportCallbackEXT function to create the VkDebugReportCallbackEXT object. The function is found in the proxy function above the class.
		createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
		createInfo.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT;	// The flags field allows you to filter which types of messages you would like to receive.
		createInfo.pfnCallback = debugCallback;	// The pfnCallback field specifies the pointer to the callback function.
		if (CreateDebugReportCallbackEXT(instance, &createInfo, nullptr, &callback) != VK_SUCCESS)	// Here the fn is actually executing and creates the extension object. The second to last parameter is again the optional allocator callback that we set to nullptr, other than that the parameters are fairly straightforward. Since the debug callback is specific to our Vulkan instance and its layers, it needs to be explicitly specified as first argument.
			throw std::runtime_error("failed to set up debug callback!");
	}

	bool checkDeviceExtensionSupport(VkPhysicalDevice device) { // Enumerates extensions (for swap chain) and checks if all of the required extensions are amongst them. It should be noted that the availability of a presentation queue implies that the swap chain extension must be supported. However, it's still good to be explicit about things, and the extension does have to be explicitly enabled.
		uint32_t extensionCount;
		vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, nullptr);

		std::vector<VkExtensionProperties> availableExtensions(extensionCount);
		vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, availableExtensions.data());

		std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());

		for (const auto& extension : availableExtensions)
			requiredExtensions.erase(extension.extensionName);

		return requiredExtensions.empty();	// We tick them off in the set and if it's empty all are supported. The alt is a nested loop like in checkValidationLayerSupport().
	}

	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device) {	// Creates and populates a SwapChainSupportDetails struct.
		SwapChainSupportDetails details;

		// 1. Surface capabilities
		vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, surface, &details.capabilities);		// All of the support querying functions like this one have the logical device and surface as first parameters because they are the core components of the swap chain.
																								// 2. Supported surface formats. It's a list of structs so it follows the familiar ritual of 2 function calls:
		uint32_t formatCount;
		vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, nullptr);
		if (formatCount != 0) {
			details.formats.resize(formatCount);		// Makes sure the vector is resized to hold all the available formats.
			vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, details.formats.data());
		}
		// 3. Supported presentation modes.
		uint32_t presentModeCount;
		vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentModeCount, nullptr);
		if (presentModeCount != 0) {
			details.presentModes.resize(presentModeCount);
			vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentModeCount, details.presentModes.data());
		}

		return details;
	}

	bool isDeviceSuitable(VkPhysicalDevice device) {	// Checks if a graphics card supports the operations we want.
		//VkPhysicalDeviceProperties deviceProperties;
		//vkGetPhysicalDeviceProperties(device, &deviceProperties);	// Gets basic device properties like name, type and supported Vulkan version.

		//VkPhysicalDeviceFeatures deviceFeatures;
		//vkGetPhysicalDeviceFeatures(device, &deviceFeatures);		// Queries support for features like texture compression and multi viewport rendering (useful for VR)

		QueueFamilyIndices indices = findQueueFamilies(device);

		bool extensionsSupported = checkDeviceExtensionSupport(device);

		bool swapChainAdequate = false;		// Swap chain support is sufficient for this program if there is at least one supported image format and one supported presentation mode given the window surface we have.
		if (extensionsSupported) {
			SwapChainSupportDetails swapChainSupport = querySwapChainSupport(device);
			swapChainAdequate = !swapChainSupport.formats.empty() && !swapChainSupport.presentModes.empty();
		}

		VkPhysicalDeviceFeatures supportedFeatures;
		vkGetPhysicalDeviceFeatures(device, &supportedFeatures);
		return indices.isComplete() && extensionsSupported && swapChainAdequate && supportedFeatures.samplerAnisotropy; //  Here a device which supports the queue families and (swap chain) extensions we want is enough. By the way checking for extensionsSupported is not a must since it's a prerequisite for the next one. Other approaches include rating all the devices and picking the best one or allowing the user to select. For a rating-based approach see: https://vulkan-tutorial.com/Drawing_a_triangle/Setup/Physical_devices_and_queue_families		... Also it's unlikely a modern graphics card does not support anisotropic filtering but we need to check for it.
	}

	void pickPhysicalDevice() {	// Used to look for and select a graphics card in the system that supports the features we need. In fact we can select any number of graphics cards and use them simultaneously, but in this tutorial we'll stick to the first graphics card that suits our needs.
		uint32_t deviceCount = 0;
		vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
		if (deviceCount == 0)
			throw std::runtime_error("Failed to find GPUs with Vulkan support!");

		std::vector<VkPhysicalDevice> devices(deviceCount);
		vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());
		for (const auto& device : devices)
			if (isDeviceSuitable(device)) {
				physicalDevice = device;
				break;
			}
		if (physicalDevice == VK_NULL_HANDLE)
			throw std::runtime_error("Failed to find a suitable GPU!");
	}

	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device) {
		QueueFamilyIndices indices;		// This is a struct defined before the class.

		uint32_t queueFamilyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

		std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

		int i = 0;
		for (const auto& queueFamily : queueFamilies) {
			// Graphics family queue
			if (queueFamily.queueCount > 0 && queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
				indices.graphicsFamily = i;
			// Present family queue
			VkBool32 presentSupport = false;	// Presenting ie. displaying rendered output on surface.
			vkGetPhysicalDeviceSurfaceSupportKHR(device, i, surface, &presentSupport);
			if (queueFamily.queueCount > 0 && presentSupport)
				indices.presentFamily = i;

			if (indices.isComplete())
				break;
			i++;
		}
		return indices;
	}

	void createLogicalDevice() {
		// Before we create the device we need to specify the number of queues we want etc in the struct below:
		QueueFamilyIndices indices = findQueueFamilies(physicalDevice);

		std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;			// The structs needed for each queue are stored in this vector
		std::set<int> uniqueQueueFamilies = { indices.graphicsFamily, indices.presentFamily };		// We need to have multiple VkDeviceQueueCreateInfo structs to create a queue from both families. An elegant way to do that is to create a set of all unique queue families that are necessary for the required queues.

		float queuePriority = 1.0f;
		for (int queueFamily : uniqueQueueFamilies) {
			VkDeviceQueueCreateInfo queueCreateInfo = {};
			queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			queueCreateInfo.queueFamilyIndex = queueFamily;		// We assign the queue family, represented by an int. Our for loop will make sure that graphicsFamily and presentFamily are different ints.
			queueCreateInfo.queueCount = 1;	// We don't really need more than 1 queue of the same family in most cases. Because we can use multiple threads but the same queue.
			queueCreateInfo.pQueuePriorities = &queuePriority;	// // Assigning this is a must, even though we only have one queue of each type. The priority is a value from 0.0f to 1.0f.
			queueCreateInfos.push_back(queueCreateInfo);
		}

		// Specifying device features we will use:
		VkPhysicalDeviceFeatures deviceFeatures = {};
		deviceFeatures.samplerAnisotropy = VK_TRUE;	// Anisotropy for texture image sampling.

		// This is the final struct we need, the usual one to create the thing.
		VkDeviceCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		// We add pointers to the 2 structs we created:
		createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
		createInfo.pQueueCreateInfos = queueCreateInfos.data();;
		createInfo.pEnabledFeatures = &deviceFeatures;
		// Device-specific extensions. The device extension we want is for the swap queue.
		createInfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtensions.size());
		createInfo.ppEnabledExtensionNames = deviceExtensions.data();
		// Validation layers
		if (enableValidationLayers) {		// We enable the same validation layers for devices as we do for the instance.
			createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
			createInfo.ppEnabledLayerNames = validationLayers.data();
		}
		else
			createInfo.enabledLayerCount = 0;

		// Instantiating the logical device
		if (vkCreateDevice(physicalDevice, &createInfo, nullptr, &device) != VK_SUCCESS)		// Logical devices don't interact directly with instances, which is why it's not included as a parameter.
			throw std::runtime_error("Failed to create logical device!");

		vkGetDeviceQueue(device, indices.graphicsFamily, 0, &graphicsQueue);	// Retrieves a queue handle. The second param is the queue family for which to retrieve the handle. 3rd param is queue index (will always be 0 cuz 1 queue per family). The last param is of type VkQueue where the thing will be stored.
		vkGetDeviceQueue(device, indices.presentFamily, 0, &presentQueue);
	}

	void createSurface() {
		if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS)		// This method executes different code depending on the platform, which is why GLFW is platform-agnostic. The last param is a pointer to the VkSurfaceKHR variable. Note pattern in having fn return success true/false and 'returning' the actual thing is done through reference parameters.
			throw std::runtime_error("Failed to create window surface!");
	}

	// Before the swap chain is created we need to find the right settings for the best possible swap chain. For each of these settings we'll have an ideal value in mind that we'll go with if it's available and otherwise we'll create some logic to find the next best thing. This function is for the first one, surface format (color depth):
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats) { // Each VkSurfaceFormatKHR entry contains a format and a colorSpace member. The format member specifies the color channels and types. For example, VK_FORMAT_B8G8R8A8_UNORM means that we store the B, G, R and alpha channels in that order with an 8 bit unsigned integer for a total of 32 bits per pixel. The colorSpace member indicates if the SRGB color space is supported or not using the VK_COLOR_SPACE_SRGB_NONLINEAR_KHR flag. Note that this flag used to be called VK_COLORSPACE_SRGB_NONLINEAR_KHR in old versions of the specification.
																										  // For the color space we'll use sRGB (standard RGB. The other option is linear RGB) if it's available, because it results in more accurate perceived colors. Working directly with SRGB colors is a little bit challenging, so we'll use standard RGB for the color format, of which one of the most common ones is VK_FORMAT_B8G8R8A8_UNORM.

																										  // The best case scenario is that the surface has no preferred format, which Vulkan indicates by only returning one VkSurfaceFormatKHR entry which has its format member set to VK_FORMAT_UNDEFINED:
		if (availableFormats.size() == 1 && availableFormats[0].format == VK_FORMAT_UNDEFINED)
			return { VK_FORMAT_B8G8R8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR };
		// If we're not free to choose any format, then we'll go through the list and see if the preferred combination is available:
		for (const auto& availableFormat : availableFormats)
			if (availableFormat.format == VK_FORMAT_B8G8R8A8_UNORM && availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
				return availableFormat;
		// If that also fails then we could start ranking the available formats based on how "good" they are, but in most cases it's okay to just settle with the first format that is specified:
		return availableFormats[0];
	}

	// Finds the second setting required to create the swap chain, the presentation mode (conditions for "swapping" images to the screen)
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes) {
		// There are 4 presentation modes:
		// 1. VK_PRESENT_MODE_IMMEDIATE_KHR: Images submitted by your application are transferred to the screen right away, which may result in tearing. Screen tearing is a visual artifact in video display where a display device shows information from multiple frames in a single screen draw. The artifact occurs when the video feed to the device is not in sync with the display's refresh rate. Called screen tearing because the screen is torn in 2. One part is from one frame and the other is from the next.
		// 2. VK_PRESENT_MODE_FIFO_KHR: The swap chain is a queue where the display takes an image from the front of the queue when the display is refreshed and the program inserts rendered images at the back of the queue. If the queue is full then the program has to wait. This is most similar to vertical sync as found in modern games. The moment that the display is refreshed is known as "vertical blank".
		// 3. VK_PRESENT_MODE_FIFO_RELAXED_KHR: This mode only differs from the previous one if the application is late and the queue was empty at the last vertical blank. Instead of waiting for the next vertical blank, the image is transferred right away when it finally arrives. This may result in visible tearing.
		// 4. VK_PRESENT_MODE_MAILBOX_KHR: This is another variation of the second mode. Instead of blocking the application when the queue is full, the images that are already queued are simply replaced with the newer ones. This mode can be used to implement triple buffering, which allows you to avoid tearing with significantly less latency issues than standard vertical sync that uses double buffering. Great explanation on what that is: anandtech.com/show/2794/2
		VkPresentModeKHR bestMode = VK_PRESENT_MODE_FIFO_KHR;	// Only this one is guaranteed to be available so we start with it.

		for (const auto& availablePresentMode : availablePresentModes)
			if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR)	// We search for triple buffering, the best one.
				return availablePresentMode;
			else if (availablePresentMode == VK_PRESENT_MODE_IMMEDIATE_KHR)		// Unfortunately some drivers currently don't properly support VK_PRESENT_MODE_FIFO_KHR, so we should prefer VK_PRESENT_MODE_IMMEDIATE_KHR if VK_PRESENT_MODE_MAILBOX_KHR is not available:
				bestMode = availablePresentMode;

		return bestMode;
	}

	// Finds the third setting required to create the swap chain, the swap extent (resolution of images in swap chain).
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities) {
		// The swap extent is the resolution of the swap chain images and it's almost always exactly equal to the resolution of the window that we're drawing to. The range of the possible resolutions is defined in the VkSurfaceCapabilitiesKHR structure. Vulkan tells us to match the resolution of the window by setting the width and height in the currentExtent member. However, some window managers do allow us to differ here and this is indicated by setting the width and height in currentExtent to a special value: the maximum value of uint32_t. In that case we'll pick the resolution that best matches the window within the minImageExtent and maxImageExtent bounds.
		// The max and min functions are used below to clamp the value of WIDTH and HEIGHT between the allowed minimum and maximum extents that are supported by the implementation. An alt is to use the C++17 clamp. See A-uIFk_uWdw on YouTube for what we're doing.
		if (capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max())	// If the window manager does not allow us to differ from the monitor resolution
			return capabilities.currentExtent;
		else {
			int width, height;
			glfwGetWindowSize(window, &width, &height);	// We get the current width and height of the window
			VkExtent2D actualExtent = { width, height };

			actualExtent.width = std::max(capabilities.minImageExtent.width, std::min(capabilities.maxImageExtent.width, actualExtent.width));
			actualExtent.height = std::max(capabilities.minImageExtent.height, std::min(capabilities.maxImageExtent.height, actualExtent.height));

			return actualExtent;
		}
	}

	void createSwapChain() {
		SwapChainSupportDetails swapChainSupport = querySwapChainSupport(physicalDevice);

		VkSurfaceFormatKHR surfaceFormat = chooseSwapSurfaceFormat(swapChainSupport.formats);
		VkPresentModeKHR presentMode = chooseSwapPresentMode(swapChainSupport.presentModes);
		VkExtent2D extent = chooseSwapExtent(swapChainSupport.capabilities);

		// Before we create it we also need to decide on one last minor thing. The number of images in the swap chain ie. the queue length:
		uint32_t imageCount = swapChainSupport.capabilities.minImageCount + 1;	// We want one more image than the minimum allowed in our implementation. The reason is that triple buffering works better if u have more than the minimum it can work with.
		if (swapChainSupport.capabilities.maxImageCount > 0 && imageCount > swapChainSupport.capabilities.maxImageCount)
			imageCount = swapChainSupport.capabilities.maxImageCount;		// A value of 0 for maxImageCount means that there is no limit besides memory requirements, which is why we need to check for that.

																			// We start filling the struct to create the swap chain:
		VkSwapchainCreateInfoKHR createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		createInfo.surface = surface;
		createInfo.minImageCount = imageCount;
		createInfo.imageFormat = surfaceFormat.format;
		createInfo.imageColorSpace = surfaceFormat.colorSpace;
		createInfo.imageExtent = extent;
		createInfo.imageArrayLayers = 1;	// The imageArrayLayers specifies the amount of layers each image consists of. This is always 1 unless you are developing a stereoscopic 3D application.
		createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;	// The imageUsage bit field specifies what kind of operations we'll use the images in the swap chain for. In this tutorial we're going to render directly to them, which means that they're used as color attachment. It is also possible that you'll render images to a separate image first to perform operations like post-processing. In that case you may use a value like VK_IMAGE_USAGE_TRANSFER_DST_BIT instead and use a memory operation to transfer the rendered image to a swap chain image.
																		// Next, we need to specify how to handle swap chain images that will be used across multiple queue families. That will be the case in our application if the graphics queue family is different from the presentation queue. We'll be drawing on the images in the swap chain from the graphics queue and then submitting them on the presentation queue. There are two ways to handle images that are accessed from multiple queues:
																		// 1. VK_SHARING_MODE_EXCLUSIVE: An image is owned by one queue family at a time and ownership must be explicitly transfered before using it in another queue family. This option offers the best performance.
																		// 2. VK_SHARING_MODE_CONCURRENT: Images can be used across multiple queue families without explicit ownership transfers.
		QueueFamilyIndices indices = findQueueFamilies(physicalDevice);
		uint32_t queueFamilyIndices[] = { (uint32_t)indices.graphicsFamily, (uint32_t)indices.presentFamily };
		if (indices.graphicsFamily != indices.presentFamily) {
			createInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;	// If the queue families differ, then we'll be using the concurrent mode in this tutorial because ownership is not straightforward.
			createInfo.queueFamilyIndexCount = 2;
			createInfo.pQueueFamilyIndices = queueFamilyIndices;	// Concurrent mode requires you to specify in advance between which queue families ownership will be shared using the queueFamilyIndexCount and pQueueFamilyIndices parameters.
		}
		else {
			createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;	// Exclusive mode with only 1 queue.
			createInfo.queueFamilyIndexCount = 0; // Optional
			createInfo.pQueueFamilyIndices = nullptr; // Optional
		}
		// Final stuff:
		createInfo.preTransform = swapChainSupport.capabilities.currentTransform;	// To specify that we don't want any pre-transformation we just set it to the currentTransform. Possible pre-transformations could have been a 90 degrees rotation or a horizontal flip.
		createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;	// The compositeAlpha field specifies if the alpha channel should be used for blending with other windows in the window system. You'll almost always want to simply ignore the alpha channel, hence VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR.
		createInfo.presentMode = presentMode;
		createInfo.clipped = VK_TRUE;	// If the clipped member is set to VK_TRUE then that means that we don't care about the color of pixels that are obscured, for example because another window is in front of them. Unless you really need to be able to read these pixels back and get predictable results, you'll get the best performance by enabling clipping.
		createInfo.oldSwapchain = VK_NULL_HANDLE;	// With Vulkan it's possible that your swap chain becomes invalid or unoptimized while your application is running, for example because the window was resized. In that case the swap chain actually needs to be recreated from scratch and a reference to the old one must be specified in this field.

		// Creating the swapchain:
		if (vkCreateSwapchainKHR(device, &createInfo, nullptr, &swapChain) != VK_SUCCESS)
			throw std::runtime_error("Failed to create swap chain!");

		// Retrieving handles to swap chain images:
		vkGetSwapchainImagesKHR(device, swapChain, &imageCount, nullptr);	// When we created the swap chain, we passed the number of desired images to a field called minImageCount. The implementation is allowed to create more images, which is why we need to explicitly query the amount again.
		swapChainImages.resize(imageCount);
		vkGetSwapchainImagesKHR(device, swapChain, &imageCount, swapChainImages.data());

		// We also need to store the format and extent for later use:
		swapChainImageFormat = surfaceFormat.format;
		swapChainExtent = extent;
	}

	VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags) {
		VkImageViewCreateInfo viewInfo = {};
		viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		viewInfo.image = image;
		// The viewType parameter allows you to treat images as 1D textures, 2D textures, 3D textures and cube maps:
		viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
		viewInfo.format = format;
		// The components field allows you to swizzle the color channels around. For example, you can map all of the channels to the red channel for a monochrome texture. You can also map constant values of 0 and 1 to a channel. In our case we'll stick to the default mapping:
		/*createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;*/
		// The subresourceRange field describes what the image's purpose is and which part of the image should be accessed. Our images will be used as color targets without any mipmapping levels or multiple layers:
		viewInfo.subresourceRange.aspectMask = aspectFlags;
		viewInfo.subresourceRange.baseMipLevel = 0;
		viewInfo.subresourceRange.levelCount = 1;
		viewInfo.subresourceRange.baseArrayLayer = 0;
		viewInfo.subresourceRange.layerCount = 1;	// Multiple layers are for stereoscopy.

		VkImageView imageView;
		if (vkCreateImageView(device, &viewInfo, nullptr, &imageView) != VK_SUCCESS)
			throw std::runtime_error("Failed to create image view!"); // An image view is sufficient to start using an image as a texture, but it's not quite ready to be used as a render target just yet (requires frame buffer).

		return imageView;
	}

	void createImageViews() {	// Creates a basic image view for every image in the swap chain so that we can use them as color targets later on.
		// Resizing list to fit all image views to be created:
		swapChainImageViews.resize(swapChainImages.size());

		for (uint32_t i = 0; i < swapChainImages.size(); i++)
			swapChainImageViews[i] = createImageView(swapChainImages[i], swapChainImageFormat, VK_IMAGE_ASPECT_COLOR_BIT);
	}

	VkShaderModule createShaderModule(const std::vector<char>& code) {	// Before we pass the shader bytecode to the pipeline, we have to wrap it in a VkShaderModule object. This fn takes the bytecode as the param and does that.
		VkShaderModuleCreateInfo createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());	// The size of the bytecode is specified in bytes, but the bytecode pointer is a uint32_t pointer rather than a char pointer. Therefore we will need to cast the pointer with reinterpret_cast as shown below.

		VkShaderModule shaderModule;
		if (vkCreateShaderModule(device, &createInfo, nullptr, &shaderModule) != VK_SUCCESS)
			throw std::runtime_error("Failed to create shader module!");
		return shaderModule;
	}

	void createRenderPass() {	// Before we can finish creating the pipeline, we need to tell Vulkan about the framebuffer attachments that will be used while rendering. We need to specify how many color and depth buffers there will be, how many samples to use for each of them and how their contents should be handled throughout the rendering operations. All of this information is wrapped in a render pass object, for which we'll create a new createRenderPass function.
		// In our case we'll have just a single color buffer attachment represented by one of the images from the swap chain.
		VkAttachmentDescription colorAttachment = {};
		colorAttachment.format = swapChainImageFormat;
		colorAttachment.samples = VK_SAMPLE_COUNT_1_BIT;	// 1 sample because we're not multisampling
		colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;	// We tell it to clean the frame buffer to a constant (we will use black) before rendering. The other option is _LOAD to preserve the existing contents of the attachment
		colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;	// Stores the rendered contents in memory (necessary to display them on screen). The other option is _DONT_CARE.
		colorAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;	// For stencil data.  Our application won't do anything with the stencil buffer, so the results of loading and storing are irrelevant. A stencil buffer is an extra buffer, in addition to the color buffer and depth buffer (z-buffering) found on modern graphics hardware. The buffer is per pixel, and works on integer values, usually with a depth of one byte per pixel. In the simplest case, the stencil buffer is used to limit the area of rendering (stenciling).
		colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
		colorAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;	// We don't care about the previous layout the image was in. We only care about its final layout.
		colorAttachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;	// Format for VkImage's to be presented in the swap chain. There is another format for images to be used as color attachments (a color attachment is a texture which attaches to a frame buffer as a render target, used for off-screen rendering)

		VkAttachmentDescription depthAttachment = {};
		depthAttachment.format = findDepthFormat();
		depthAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
		depthAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
		depthAttachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;	// This time we don't care about storing the depth data (storeOp), because it will not be used after drawing has finished.
		depthAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
		depthAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
		depthAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
		depthAttachment.finalLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

		// A single render pass can consist of multiple subpasses. Subpasses are subsequent rendering operations that depend on the contents of framebuffers in previous passes. We will use a single subpass.
		VkAttachmentReference colorAttachmentRef = {};	// Every subpass needs a VKAttachmentReference
		colorAttachmentRef.attachment = 0; // The attachment parameter specifies which attachment to reference by its index in the attachment descriptions array. Our array consists of a single VkAttachmentDescription, so its index is 0.
		colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;	// The layout specifies which layout we would like the attachment to have during a subpass that uses this reference. Vulkan will automatically transition the attachment to this layout when the subpass is started. We intend to use the attachment to function as a color buffer and the VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL layout will give us the best performance, as its name implies. The framebuffer contains (often) the depth, stencil, color, and accumulation buffers. The color buffers are the most important part, but they are only one part. So every frame has colors, depths etc.

		VkAttachmentReference depthAttachmentRef = {};
		depthAttachmentRef.attachment = 1;
		depthAttachmentRef.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

		VkSubpassDescription subpass = {};	// The subpass
		subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;	// We are saying its a graphics subpass. The other thing is an advanced feature called a compute subpass.
		subpass.colorAttachmentCount = 1;
		subpass.pColorAttachments = &colorAttachmentRef;
		subpass.pDepthStencilAttachment = &depthAttachmentRef;	// Btw other attachments can be pInputAttachments (attachment read from shader), pResolveAttachments (attachment used for multisampling).

		// Subpass dependencies. Need to specify memory and execution dependencies between subpasses. We have only a single subpass right now, but the operations right before and right after this subpass also count as implicit "subpasses". There are two built-in dependencies that take care of the transition at the start of the render pass and at the end of the render pass, but the former does not occur at the right time. It assumes that the transition occurs at the start of the pipeline, but we haven't acquired the image yet at that point! There are two ways to deal with this problem. We could change the waitStages for the imageAvailableSemaphore to VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT to ensure that the render passes don't begin until the image is available, or we can make the render pass wait for the VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT stage. We use the second option.
		VkSubpassDependency dependency = {};
		dependency.srcSubpass = VK_SUBPASS_EXTERNAL;	// The first two fields specify the indices of the dependency and the dependent subpass. The special value VK_SUBPASS_EXTERNAL refers to the implicit subpass before or after the render pass depending on whether it is specified in srcSubpass or dstSubpass.
		dependency.dstSubpass = 0;	// The index 0 refers to our subpass, which is the first and only one. The dstSubpass must always be higher than srcSubpass to prevent cycles in the dependency graph.
		// The next two fields specify the operations to wait on and the stages in which these operations occur.
		dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;	// We need to wait for the swap chain to finish reading from the image before we can access it. This can be accomplished by waiting on the color attachment output stage itself.
		dependency.srcAccessMask = 0;
		dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
		dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

		std::array<VkAttachmentDescription, 2> attachments = { colorAttachment, depthAttachment };
		// Creating the render pass
		VkRenderPassCreateInfo renderPassInfo = {};
		renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
		renderPassInfo.attachmentCount = static_cast<uint32_t>(attachments.size());
		renderPassInfo.pAttachments = attachments.data();
		renderPassInfo.subpassCount = 1;
		renderPassInfo.pSubpasses = &subpass;
		renderPassInfo.dependencyCount = 1;
		renderPassInfo.pDependencies = &dependency;

		if (vkCreateRenderPass(device, &renderPassInfo, nullptr, &renderPass) != VK_SUCCESS)
			throw std::runtime_error("Failed to create render pass!");
	}

	void createDescriptorSetLayout() {	// We need to provide details about every descriptor binding used in the shaders for pipeline creation.
		VkDescriptorSetLayoutBinding uboLayoutBinding = {};	// Every binding needs to be described through a VkDescriptorSetLayoutBinding struct.
		uboLayoutBinding.binding = 0;
		uboLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		uboLayoutBinding.descriptorCount = 1;	// Number of values in array. Our MVP transformation is in a single uniform buffer object, so we're using a descriptorCount of 1.
		uboLayoutBinding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;	// We're only referencing the descriptor from the vertex shader so we need only that shader stage.
		uboLayoutBinding.pImmutableSamplers = nullptr; // Optional. The pImmutableSamplers field is relevant for image sampling related descriptors.

		VkDescriptorSetLayoutBinding samplerLayoutBinding = {};	// For a combined image sampler descriptor. This descriptor makes it possible for shaders to access an image resource through a sampler object (we already made one).
		samplerLayoutBinding.binding = 1;
		samplerLayoutBinding.descriptorCount = 1;
		samplerLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		samplerLayoutBinding.pImmutableSamplers = nullptr;
		samplerLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;

		std::array<VkDescriptorSetLayoutBinding, 2> bindings = { uboLayoutBinding, samplerLayoutBinding };
		VkDescriptorSetLayoutCreateInfo layoutInfo = {};
		layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		layoutInfo.bindingCount = static_cast<uint32_t>(bindings.size());
		layoutInfo.pBindings = bindings.data();

		if (vkCreateDescriptorSetLayout(device, &layoutInfo, nullptr, &descriptorSetLayout) != VK_SUCCESS)
			throw std::runtime_error("Failed to create descriptor set layout!");
	}

	void createGraphicsPipeline() {
		auto vertShaderCode = readFile("shaders/vert.spv");
		auto fragShaderCode = readFile("shaders/frag.spv");
		VkShaderModule vertShaderModule = createShaderModule(vertShaderCode);	// The shader module objects are only required during the pipeline creation process, so instead of declaring them as class members we declare them here.
		VkShaderModule fragShaderModule = createShaderModule(fragShaderCode);

		// Vertex shader
		VkPipelineShaderStageCreateInfo vertShaderStageInfo = {};
		vertShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;		// We tell Vulkan in which pipeline stage the shader is going to be used.
		vertShaderStageInfo.module = vertShaderModule;	// The shader module containing the code
		vertShaderStageInfo.pName = "main";		// Which function to invoke. That means that it's possible to combine multiple fragment shaders into a single shader module and use different entry points to differentiate between their behaviors.
		// There is one more (optional) member, pSpecializationInfo, which we won't be using here, but is worth discussing. It allows you to specify values for shader constants. You can use a single shader module where its behavior can be configured at pipeline creation by specifying different values for the constants used in it. This is more efficient than configuring the shader using variables at render time, because the compiler can do optimizations like eliminating if statements that depend on these values. If you don't have any constants like that, then you can set the member to nullptr, which our struct initialization does automatically.

		// Fragment shader
		VkPipelineShaderStageCreateInfo fragShaderStageInfo = {};
		fragShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
		fragShaderStageInfo.module = fragShaderModule;
		fragShaderStageInfo.pName = "main";

		VkPipelineShaderStageCreateInfo shaderStages[] = { vertShaderStageInfo, fragShaderStageInfo };

		// Vertex input: Struct which describes the format of the vertex data that will be passed to the vertex shader.
		VkPipelineVertexInputStateCreateInfo vertexInputInfo = {};
		vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		auto bindingDescription = Vertex::getBindingDescription();	// In this line and the next one we prepare the graphics pipeline to accept vertex data in the Vertex format.
		auto attributeDescriptions = Vertex::getAttributeDescriptions();
		vertexInputInfo.vertexBindingDescriptionCount = 1;
		vertexInputInfo.pVertexBindingDescriptions = &bindingDescription; // Optional. Set it to null pointer if you are hard-coding the vertices in the vertex shader.
		vertexInputInfo.vertexAttributeDescriptionCount = static_cast<uint32_t>(attributeDescriptions.size());
		vertexInputInfo.pVertexAttributeDescriptions = attributeDescriptions.data(); // Also optional.

		// Input assembly: Struct which describes two things: what kind of geometry will be drawn from the vertices and if primitive restart should be enabled. The former is specified in the topology member.
		VkPipelineInputAssemblyStateCreateInfo inputAssembly = {};
		inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;	// Triangle from every 3 vertices without reuse
		inputAssembly.primitiveRestartEnable = VK_FALSE;	// If you set this to true then you can use _STRIP topologies where the end vertex of every line is used as start vertex for the next line and you can implement some optimization there.

		// A viewport basically describes the region of the framebuffer that the output will be rendered to. This will almost always be (0, 0) to (width, height)
		VkViewport viewport = {};
		viewport.x = 0.0f;
		viewport.y = 0.0f;
		viewport.width = (float)swapChainExtent.width;
		viewport.height = (float)swapChainExtent.height;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		// While viewports define the transformation from the image to the framebuffer, scissor rectangles define in which regions pixels will actually be stored. Any pixels outside the scissor rectangles will be discarded by the rasterizer. They function like a filter rather than a transformation. Here we simply want to draw to the entire framebuffer, so we'll specify a scissor rectangle that covers it entirely:
		VkRect2D scissor = {};
		scissor.offset = { 0, 0 };
		scissor.extent = swapChainExtent;

		// Now this viewport and scissor rectangle need to be combined into a viewport state using the VkPipelineViewportStateCreateInfo struct. It is possible to use multiple viewports and scissor rectangles on some graphics cards, so its members reference an array of them.
		VkPipelineViewportStateCreateInfo viewportState = {};
		viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		viewportState.viewportCount = 1;
		viewportState.pViewports = &viewport;
		viewportState.scissorCount = 1;
		viewportState.pScissors = &scissor;

		// Rasterizer. Converts geometry to fragments for the fragment shader. Also performs depth testing (depth buffering / z-buffering: It's the management of 3D coordinates and it's the solution to the visibility problem (what's visible and what's not), alt to the painter's algorithm. Basically when a pixel is rendered its depth is stored in a buffer. If another object must be rendered in the same pixel, then the depths are compared and it's decided which object's pixel should be there), (back-)face culling (determining if polygons are visible and not rendering them if they aren't), scissor test (discards fragments outside the scissor).
		VkPipelineRasterizationStateCreateInfo rasterizer = {};
		rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		rasterizer.depthClampEnable = VK_FALSE;	// If depthClampEnable is set to VK_TRUE, then fragments that are beyond the near and far planes are clamped to them as opposed to discarding them. This is useful in some special cases like shadow maps.
		rasterizer.rasterizerDiscardEnable = VK_FALSE;	// If rasterizerDiscardEnable is set to VK_TRUE, then geometry never passes through the rasterizer stage.
		rasterizer.polygonMode = VK_POLYGON_MODE_FILL;	// fill the area of the polygon with fragments. The other option is _LINE which draws only the edges as lines and _POINT which draws only the vertices.
		rasterizer.lineWidth = 1.0f;
		rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;	// The cullMode variable determines the type of face culling to use. You can disable culling, cull the front faces, cull the back faces or both.
		rasterizer.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;	// The frontFace variable specifies the vertex order for faces to be considered front-facing and can be clockwise or counterclockwise. Normally it should be CLOCKWISE. But  because of the Y-flip we did in the projection matrix, the vertices are now being drawn in clockwise order instead of counter-clockwise order.
		rasterizer.depthBiasEnable = VK_FALSE;		// Setting this to true alters the depth values with a bias and is only used for shadow mapping etc.
		rasterizer.depthBiasConstantFactor = 0.0f; // Optional
		rasterizer.depthBiasClamp = 0.0f; // Optional
		rasterizer.depthBiasSlopeFactor = 0.0f; // Optional

		// Multisampling (One way to perform anti-aliasing.  It works by combining the fragment shader results of multiple polygons that rasterize to the same pixel. This mainly occurs along edges, which is also where the most noticeable aliasing artifacts occur. Because it doesn't need to run the fragment shader multiple times if only one polygon maps to a pixel, it is significantly less expensive than simply rendering to a higher resolution and then downscaling. Enabling it requires enabling a GPU feature.)
		VkPipelineMultisampleStateCreateInfo multisampling = {};
		multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		multisampling.sampleShadingEnable = VK_FALSE;	// We won't be using it for now
		multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
		multisampling.minSampleShading = 1.0f; // Optional
		multisampling.pSampleMask = nullptr; // Optional
		multisampling.alphaToCoverageEnable = VK_FALSE; // Optional
		multisampling.alphaToOneEnable = VK_FALSE; // Optional

		VkPipelineDepthStencilStateCreateInfo depthStencil = {};
		depthStencil.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
		depthStencil.depthTestEnable = VK_TRUE;	// The depthTestEnable field specifies if the depth of new fragments should be compared to the depth buffer to see if they should be discarded.
		depthStencil.depthWriteEnable = VK_TRUE; // The depthWriteEnable field specifies if the new depth of fragments that pass the depth test should actually be written to the depth buffer. This is useful for drawing transparent objects. They should be compared to the previously rendered opaque objects, but not cause further away transparent objects to not be drawn.
		depthStencil.depthCompareOp = VK_COMPARE_OP_LESS;	// The depthCompareOp field specifies the comparison that is performed to keep or discard fragments. We're sticking to the convention of lower depth = closer, so the depth of new fragments should be less.
		depthStencil.depthBoundsTestEnable = VK_FALSE;	// Feature for only keeping fragments that fall within a specified depth range (you specify the range in another field)
		depthStencil.stencilTestEnable = VK_FALSE;
		// Fields for stencil buffer operations:
		depthStencil.stencilTestEnable = VK_FALSE;
		depthStencil.front = {}; // Optional
		depthStencil.back = {}; // Optional

		// Color blending struct 1: After a fragment shader has returned a color, it needs to be combined with the color that is already in the framebuffer. The first struct, VkPipelineColorBlendAttachmentState contains the configuration per attached framebuffer and the second struct, VkPipelineColorBlendStateCreateInfo contains the global color blending settings. In our case we only have one framebuffer.
		VkPipelineColorBlendAttachmentState colorBlendAttachment = {};
		colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
		colorBlendAttachment.blendEnable = VK_FALSE;	// If blendEnable is set to VK_FALSE, then the new color from the fragment shader is passed through unmodified. So here we are not using color blending.
		colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_ONE; // Optional
		colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
		colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD; // Optional
		colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE; // Optional
		colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
		colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD; // Optional
		// If we were to use alpha blending for color blending, where the new color is blended with the old color based on its opacity:
		/*colorBlendAttachment.blendEnable = VK_TRUE;
		colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
		colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
		colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD;
		colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE;
		colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
		colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD;*/

		// Color blending struct 2
		VkPipelineColorBlendStateCreateInfo colorBlending = {};
		colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		colorBlending.logicOpEnable = VK_FALSE;	// If you want to use bitwise operations to blend colors, this should be true.
		colorBlending.logicOp = VK_LOGIC_OP_COPY;	// Optional. If you are using a bitwise operation, you would specify it here.
		colorBlending.attachmentCount = 1;
		colorBlending.pAttachments = &colorBlendAttachment;
		colorBlending.blendConstants[0] = 0.0f;	// Optional
		colorBlending.blendConstants[1] = 0.0f; // Optional
		colorBlending.blendConstants[2] = 0.0f; // Optional
		colorBlending.blendConstants[3] = 0.0f; // Optional

		// Dynamic state struct: A limited amount of the state that we've specified in the previous structs can actually be changed without recreating the pipeline. Examples are the size of the viewport, line width and blend constants. If you want to do that, then you'll have to fill in a VkPipelineDynamicStateCreateInfo structure like this:
		/*VkDynamicState dynamicStates[] = {
		VK_DYNAMIC_STATE_VIEWPORT,
		VK_DYNAMIC_STATE_LINE_WIDTH
		};
		VkPipelineDynamicStateCreateInfo dynamicState = {};
		dynamicState.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		dynamicState.dynamicStateCount = 2;
		dynamicState.pDynamicStates = dynamicStates;*/

		// Finally we declare any <code>uniform</code> values in shaders, which are globals similar to dynamic state variables that can be changed at drawing time to alter the behavior of your shaders without having to recreate them. They are commonly used to pass the transformation matrix to the vertex shader, or to create texture samplers in the fragment shader.
		VkPipelineLayoutCreateInfo pipelineLayoutInfo = {};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 1; // Optional. We are using it however. The 1 represents the one descriptor set layout.
		pipelineLayoutInfo.pSetLayouts = &descriptorSetLayout; // Optional. We use it to tell Vulkan which descriptors the shaders will be using.
		pipelineLayoutInfo.pushConstantRangeCount = 0;	// Optional. Push constants are yet another way to pass dynamic values to shaders. We aren't using any.
		pipelineLayoutInfo.pPushConstantRanges = 0; // Optional

		if (vkCreatePipelineLayout(device, &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS)
			throw std::runtime_error("Failed to create pipeline layout!");

		// Creating graphics pipeline
		VkGraphicsPipelineCreateInfo pipelineInfo = {};
		pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		pipelineInfo.stageCount = 2;
		pipelineInfo.pStages = shaderStages;
		// We reference everything we made:
		pipelineInfo.pVertexInputState = &vertexInputInfo;
		pipelineInfo.pInputAssemblyState = &inputAssembly;
		pipelineInfo.pViewportState = &viewportState;
		pipelineInfo.pRasterizationState = &rasterizer;
		pipelineInfo.pMultisampleState = &multisampling;
		pipelineInfo.pDepthStencilState = &depthStencil;
		pipelineInfo.pColorBlendState = &colorBlending;
		pipelineInfo.pDynamicState = nullptr; // Optional
		pipelineInfo.layout = pipelineLayout;
		pipelineInfo.renderPass = renderPass;
		pipelineInfo.subpass = 0;
		pipelineInfo.basePipelineHandle = VK_NULL_HANDLE;	// Optional. Used if u want to derive your pipeline from an existing one. You specifiy the handle of an existing pipeline. or specify it by index (below line)
		pipelineInfo.basePipelineIndex = -1; // Optional. We specify an invalid index because we don't want to use this.

		if (vkCreateGraphicsPipelines(device, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &graphicsPipeline) != VK_SUCCESS)	// The vkCreateGraphicsPipelines function actually has more parameters than the usual object creation functions in Vulkan. It is designed to take multiple VkGraphicsPipelineCreateInfo objects and create multiple VkPipeline objects in a single call. The second parameter, for which we've passed the VK_NULL_HANDLE argument, references an optional VkPipelineCache object. A pipeline cache can be used to store and reuse data relevant to pipeline creation across multiple calls to vkCreateGraphicsPipelines and even across program executions if the cache is stored to a file. This makes it possible to significantly speed up pipeline creation at a later time.
			throw std::runtime_error("Failed to create graphics pipeline!");

		vkDestroyShaderModule(device, fragShaderModule, nullptr);
		vkDestroyShaderModule(device, vertShaderModule, nullptr);
	}

	void createFramebuffers() {
		swapChainFramebuffers.resize(swapChainImageViews.size());	// Resizing container to hold all frame buffers. A framebuffer object references all of the VkImageView objects that represent the attachments. Here we have only one attachement, the color buffer.

		// Iterating through the views to create buffers from them:
		for (size_t i = 0; i < swapChainImageViews.size(); i++) {
			std::array<VkImageView, 2> attachments = {
				swapChainImageViews[i],
				depthImageView
			};

			VkFramebufferCreateInfo framebufferInfo = {};
			framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
			framebufferInfo.renderPass = renderPass;	// With which render pass the frame buffere needs to be compatible
			framebufferInfo.attachmentCount = static_cast<uint32_t>(attachments.size());
			framebufferInfo.pAttachments = attachments.data();
			framebufferInfo.width = swapChainExtent.width;
			framebufferInfo.height = swapChainExtent.height;
			framebufferInfo.layers = 1;

			if (vkCreateFramebuffer(device, &framebufferInfo, nullptr, &swapChainFramebuffers[i]) != VK_SUCCESS)
				throw std::runtime_error("Failed to create framebuffer!");
		}
	}

	void createCommandPool() {
		QueueFamilyIndices queueFamilyIndices = findQueueFamilies(physicalDevice);

		VkCommandPoolCreateInfo poolInfo = {};
		poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
		poolInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily;
		poolInfo.flags = 0; // Optional. There are 2 flags we can use to indicate things like the command buffers need to be rerecorded with new commands very often or to control rerecording. We don't need to rerecord.
		if (vkCreateCommandPool(device, &poolInfo, nullptr, &commandPool) != VK_SUCCESS)
			throw std::runtime_error("Failed to create command pool!");
	}

	bool hasStencilComponent(VkFormat format) {
		return format == VK_FORMAT_D32_SFLOAT_S8_UINT || format == VK_FORMAT_D24_UNORM_S8_UINT;
	}

	VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features) {	// For the depth buffer image. The support of a format depends on the tiling mode and usage, so we must also include these as parameters.
		for (VkFormat format : candidates) {
			VkFormatProperties props;
			vkGetPhysicalDeviceFormatProperties(physicalDevice, format, &props);

			if (tiling == VK_IMAGE_TILING_LINEAR && (props.linearTilingFeatures & features) == features)
				return format;
			else if (tiling == VK_IMAGE_TILING_OPTIMAL && (props.optimalTilingFeatures & features) == features)
				return format;
		}
		throw std::runtime_error("Failed to find supported format!");
	}

	VkFormat findDepthFormat() {
		return findSupportedFormat(
			{ VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT },
			VK_IMAGE_TILING_OPTIMAL,
			VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT
		);
	}

	void createDepthResources() {	// A depth attachment is based on an image, just like the color attachment. The difference is that the swap chain will not automatically create depth images for us. The depth image should have the same resolution as the color attachment. The format must contain a depth component, indicated by _D??_ in the VK_FORMAT_. eg. VK_FORMAT_D32_SFLOAT: 32-bit float for depth, VK_FORMAT_D32_SFLOAT_S8_UINT: 32-bit signed float for depth and 8 bit stencil component. The stencil component is used for stencil tests, which is an additional test that can be combined with depth testing. Stencil buffering is usually combined with depth buffering.
		VkFormat depthFormat = findDepthFormat();
		createImage(swapChainExtent.width, swapChainExtent.height, depthFormat, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, depthImage, depthImageMemory);
		depthImageView = createImageView(depthImage, depthFormat, VK_IMAGE_ASPECT_DEPTH_BIT);

		transitionImageLayout(depthImage, depthFormat, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL); // Pipeline barrier to transition depth image to a layout suitable for depth attachment usage.
	}

	void createImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory) {
		VkImageCreateInfo imageInfo = {};
		imageInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
		imageInfo.imageType = VK_IMAGE_TYPE_2D;
		imageInfo.extent.width = width;
		imageInfo.extent.height = height;
		imageInfo.extent.depth = 1;
		imageInfo.mipLevels = 1;
		imageInfo.arrayLayers = 1;
		imageInfo.format = format;	// We should use the same format for the texels as the pixels in the buffer, otherwise the copy operation will fail.
		imageInfo.tiling = tiling;
		imageInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
		imageInfo.usage = usage;
		imageInfo.samples = VK_SAMPLE_COUNT_1_BIT;	// For multisampling
		imageInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
		imageInfo.flags = 0; // Optional

		if (vkCreateImage(device, &imageInfo, nullptr, &image) != VK_SUCCESS)
			throw std::runtime_error("Failed to create image!");

		VkMemoryRequirements memRequirements;
		vkGetImageMemoryRequirements(device, image, &memRequirements);

		VkMemoryAllocateInfo allocInfo = {};
		allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		allocInfo.allocationSize = memRequirements.size;
		allocInfo.memoryTypeIndex = findMemoryType(memRequirements.memoryTypeBits, properties);

		if (vkAllocateMemory(device, &allocInfo, nullptr, &imageMemory) != VK_SUCCESS)
			throw std::runtime_error("Failed to allocate image memory!");

		vkBindImageMemory(device, image, imageMemory, 0);
	}

	VkCommandBuffer beginSingleTimeCommands() {
		VkCommandBufferAllocateInfo allocInfo = {};
		allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
		allocInfo.commandPool = commandPool;
		allocInfo.commandBufferCount = 1;

		VkCommandBuffer commandBuffer;
		vkAllocateCommandBuffers(device, &allocInfo, &commandBuffer);

		VkCommandBufferBeginInfo beginInfo = {};
		beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

		vkBeginCommandBuffer(commandBuffer, &beginInfo);

		return commandBuffer;
	}

	void endSingleTimeCommands(VkCommandBuffer commandBuffer) {
		vkEndCommandBuffer(commandBuffer);

		VkSubmitInfo submitInfo = {};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		submitInfo.commandBufferCount = 1;
		submitInfo.pCommandBuffers = &commandBuffer;

		vkQueueSubmit(graphicsQueue, 1, &submitInfo, VK_NULL_HANDLE);
		vkQueueWaitIdle(graphicsQueue);

		vkFreeCommandBuffers(device, commandPool, 1, &commandBuffer);
	}

	void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout) {	// Handles image layout transitions
		VkCommandBuffer commandBuffer = beginSingleTimeCommands();

		VkImageMemoryBarrier barrier = {};	// One of the most common ways to perform layout transitions is using an image memory barrier, a pipeline barrier.
		barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
		barrier.oldLayout = oldLayout;	// It is possible to use VK_IMAGE_LAYOUT_UNDEFINED as oldLayout if you don't care about the existing contents of the image.
		barrier.newLayout = newLayout;
		barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;	// If you are using the barrier to transfer queue family ownership, then these two fields should be the indices of the queue families.
		barrier.image = image;

		if (newLayout == VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL) {
			barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
			if (hasStencilComponent(format))
				barrier.subresourceRange.aspectMask |= VK_IMAGE_ASPECT_STENCIL_BIT;	// Bitwise or with the stencil bit includes it into the aspect mask because before the bit was unset.
		}
		else
			barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;

		barrier.subresourceRange.baseMipLevel = 0;
		barrier.subresourceRange.levelCount = 1;
		barrier.subresourceRange.baseArrayLayer = 0;
		barrier.subresourceRange.layerCount = 1;

		VkPipelineStageFlags sourceStage;
		VkPipelineStageFlags destinationStage;

		// Barriers are primarily used for synchronization purposes, so you must specify which types of operations that involve the resource must happen before the barrier, and which operations that involve the resource must wait on the barrier. The right values depend on the old and new layout, so we need if statements to set the values of barrier.srcAccessMask = 0; and barrier.dstAccessMask = 0;
		if (oldLayout == VK_IMAGE_LAYOUT_UNDEFINED && newLayout == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL) {
			barrier.srcAccessMask = 0;
			barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;

			sourceStage = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
			destinationStage = VK_PIPELINE_STAGE_TRANSFER_BIT;
		}
		else if (oldLayout == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL && newLayout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL) {
			barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
			barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;

			sourceStage = VK_PIPELINE_STAGE_TRANSFER_BIT;
			destinationStage = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
		}
		else if (oldLayout == VK_IMAGE_LAYOUT_UNDEFINED && newLayout == VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL) {
			barrier.srcAccessMask = 0;
			barrier.dstAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;

			sourceStage = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
			destinationStage = VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT;
		}
		else
			throw std::invalid_argument("Unsupported layout transition!");

		vkCmdPipelineBarrier(	// fn used to submit all pipeline barriers. The parameters beside each other are pairs and are considered the same param. The last three pairs of parameters reference arrays of pipeline barriers of the three available types: memory barriers, buffer memory barriers, and image memory barriers like the one we're using here.
			commandBuffer,
			sourceStage, destinationStage,
			0,
			0, nullptr,
			0, nullptr,
			1, &barrier
		);

		endSingleTimeCommands(commandBuffer);
	}

	void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height) {
		VkCommandBuffer commandBuffer = beginSingleTimeCommands();

		// We need to specify which part of the buffer is going to be copied to which part of the image. This happens through VkBufferImageCopy structs:
		VkBufferImageCopy region = {};
		region.bufferOffset = 0;
		region.bufferRowLength = 0;
		region.bufferImageHeight = 0;	// The bufferRowLength and bufferImageHeight fields specify how the pixels are laid out in memory. For example, you could have some padding bytes between rows of the image. Specifying 0 for both indicates that the pixels are simply tightly packed like they are in our case.
		// The imageSubresource, imageOffset and imageExtent fields indicate to which part of the image we want to copy the pixels:
		region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		region.imageSubresource.mipLevel = 0;
		region.imageSubresource.baseArrayLayer = 0;
		region.imageSubresource.layerCount = 1;
		region.imageOffset = { 0, 0, 0 };
		region.imageExtent = {
			width,
			height,
			1
		};

		// Buffer to image copy operations are enqueued using the vkCmdCopyBufferToImage function:
		vkCmdCopyBufferToImage(commandBuffer, buffer, image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &region);	// The fourth parameter indicates which layout the image is currently using. We're assuming here that the image has already been transitioned to the layout that is optimal for copying pixels to.

		endSingleTimeCommands(commandBuffer);
	}

	void createTextureImage() {	// We load an image and upload it into a Vulkan image object.
		// Loading image using the stb library
		int texWidth, texHeight, texChannels;	// tex stands for texel. A texel, texture element, or texture pixel is the fundamental unit of a texture map, used in computer graphics.
		stbi_uc* pixels = stbi_load(TEXTURE_PATH.c_str(), &texWidth, &texHeight, &texChannels, STBI_rgb_alpha);	// The stbi_load function takes the file path and number of channels to load as arguments. The STBI_rgb_alpha value forces the image to be loaded with an alpha channel, even if it doesn't have one, which is nice for consistency with other textures in the future. The middle three parameters are outputs for the width, height and actual number of channels in the image. The pointer that is returned is the first element in an array of pixel values. The pixels are laid out row by row with 4 bytes per pixel in the case of STBI_rgba_alpha for a total of texWidth * texHeight * 4 values.
		VkDeviceSize imageSize = texWidth * texHeight * 4;
		if (!pixels)
			throw std::runtime_error("Failed to load texture image (textures/texture.jpg)!");

		// Create staging buffer
		VkBuffer stagingBuffer;
		VkDeviceMemory stagingBufferMemory;
		createBuffer(imageSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);

		// We can then directly copy the pixel values that we got from the image loading library to the buffer:
		void* data;
		vkMapMemory(device, stagingBufferMemory, 0, imageSize, 0, &data);
		memcpy(data, pixels, static_cast<size_t>(imageSize));
		vkUnmapMemory(device, stagingBufferMemory);

		// Cleanup original pixel array
		stbi_image_free(pixels);

		createImage(texWidth, texHeight, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, textureImage, textureImageMemory);

		// Copying staging buffer to image texture
		transitionImageLayout(textureImage, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);	// The image was created with the VK_IMAGE_LAYOUT_UNDEFINED layout, so that one should be specified as old layout when transitioning textureImage.
		copyBufferToImage(stagingBuffer, textureImage, static_cast<uint32_t>(texWidth), static_cast<uint32_t>(texHeight));
		transitionImageLayout(textureImage, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);	// To be able to start sampling from the texture image in the shader, we need one last transition to prepare it for shader access

		vkDestroyBuffer(device, stagingBuffer, nullptr);
		vkFreeMemory(device, stagingBufferMemory, nullptr);
	}

	void createTextureImageView() {	// Images are accessed through image views rather than directly. The previous method called createImageViews() was for swap chain and framebuffer images. This one is for the texture image.
		textureImageView = createImageView(textureImage, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_ASPECT_COLOR_BIT);	// Btw this image format is supported by almost all graphics cards.
	}

	void createTextureSampler() {	// It is possible for shaders to read texels directly from images, but that is not very common when they are used as textures. Textures are usually accessed through samplers, which will apply filtering and transformations to compute the final color that is retrieved. These filters are helpful to deal with problems like oversampling. Consider a texture that is mapped to geometry with more fragments than texels. Undersampling is the opposite problem, where you have more texels than fragments. This will lead to artifacts when sampling high frequency patterns like a checkerboard texture at a sharp angle. The texture turns into a blurry mess in the distance. The solution to this is anisotropic filtering, which can also be applied automatically by a sampler. In 3D computer graphics, anisotropic filtering (abbreviated AF) is a method of enhancing the image quality of textures on surfaces of computer graphics that are at oblique viewing angles with respect to the camera. Aside from these filters, a sampler can also take care of transformations. It determines what happens when you try to read texels outside the image through its addressing mode.
		VkSamplerCreateInfo samplerInfo = {};
		samplerInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
		samplerInfo.magFilter = VK_FILTER_LINEAR;	// The magFilter and minFilter fields specify how to interpolate texels that are magnified or minified. Magnification concerns the oversampling problem describes above, and minification concerns undersampling. The choices are VK_FILTER_NEAREST and VK_FILTER_LINEAR.
		samplerInfo.minFilter = VK_FILTER_LINEAR;
		samplerInfo.addressModeU = VK_SAMPLER_ADDRESS_MODE_REPEAT; // Note that the axes are called U, V and W instead of X, Y and Z. This is a convention for texture space coordinates.
		samplerInfo.addressModeV = VK_SAMPLER_ADDRESS_MODE_REPEAT; // VK_SAMPLER_ADDRESS_MODE_REPEAT: Repeat the texture when going beyond the image dimensions. If the image is too small tiles it. The other useful option is _CLAMP_TO_EDGE. Though this is really the most common option since it's used in tiling textures.
		samplerInfo.addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT;
		samplerInfo.anisotropyEnable = VK_TRUE;
		samplerInfo.maxAnisotropy = 16;	// The maxAnisotropy field limits the amount of texel samples that can be used to calculate the final color. A lower value results in better performance, but lower quality results. There is no graphics hardware available today that will use more than 16 samples, because the difference is negligible beyond that point.
		samplerInfo.borderColor = VK_BORDER_COLOR_INT_OPAQUE_BLACK;	// The borderColor field specifies which color is returned when sampling beyond the image with clamp to border addressing mode.
		samplerInfo.unnormalizedCoordinates = VK_FALSE;	// The unnormalizedCoordinates field specifies which coordinate system you want to use to address texels in an image. If this field is VK_TRUE, then you can simply use coordinates within the [0, texWidth) and [0, texHeight) range. If it is VK_FALSE, then the texels are addressed using the [0, 1) range on all axes. Real-world applications almost always use normalized coordinates, because then it's possible to use textures of varying resolutions with the exact same coordinates.
		samplerInfo.compareEnable = VK_FALSE;
		samplerInfo.compareOp = VK_COMPARE_OP_ALWAYS;
		samplerInfo.mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;

		if (vkCreateSampler(device, &samplerInfo, nullptr, &textureSampler) != VK_SUCCESS)
			throw std::runtime_error("Failed to create texture sampler!");
	}

	void createCommandBuffers() {
		commandBuffers.resize(swapChainFramebuffers.size());

		// Allocating command buffers
		VkCommandBufferAllocateInfo allocInfo = {};
		allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		allocInfo.commandPool = commandPool;
		allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;	// SECONDARY buffers cannot be submitted to a queue for execution, instead, they call a PRIMARY buffer to do that. They are used for common operations among multiple buffers.
		allocInfo.commandBufferCount = (uint32_t)commandBuffers.size();
		if (vkAllocateCommandBuffers(device, &allocInfo, commandBuffers.data()) != VK_SUCCESS)
			throw std::runtime_error("Failed to allocate command buffers!");

		for (size_t i = 0; i < commandBuffers.size(); i++) {
			// Starting command buffer recording
			VkCommandBufferBeginInfo beginInfo = {};
			beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
			beginInfo.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;	// Again the other options are related to rerecording or it being a secondary buffer. Our chosen one btw allows the buffer to be resubmitted while it is also pending execution. We use it because we may already be scheduling the drawing commands for the next frame while the last frame is not finished yet.
			beginInfo.pInheritanceInfo = nullptr; // Optional. The pInheritanceInfo parameter is only relevant for secondary command buffers. It specifies which state to inherit from the calling primary command buffers.
			vkBeginCommandBuffer(commandBuffers[i], &beginInfo);

			// Starting a render pass
			VkRenderPassBeginInfo renderPassInfo = {};
			renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
			renderPassInfo.renderPass = renderPass;
			renderPassInfo.framebuffer = swapChainFramebuffers[i];
			renderPassInfo.renderArea.offset = { 0, 0 };
			renderPassInfo.renderArea.extent = swapChainExtent;	//  The render area defines where shader loads and stores will take place. The pixels outside this region will have undefined values.

			std::array<VkClearValue, 2> clearValues = {};
			clearValues[0].color = { 0.0f, 0.0f, 0.0f, 1.0f };	// // Clear values to use for VK_ATTACHMENT_LOAD_OP_CLEAR. We are using black with 100% opacity.
			clearValues[1].depthStencil = { 1.0f, 0 };	// The range of depths in the depth buffer is 0.0 to 1.0 in Vulkan, where 1.0 lies at the far view plane and 0.0 at the near view plane. The initial value at each point in the depth buffer should be the furthest possible depth, which is 1.0.
			renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
			renderPassInfo.pClearValues = clearValues.data();

			vkCmdBeginRenderPass(commandBuffers[i], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);	// We begin the render pass. All of the functions that record commands can be recognized by their vkCmd prefix. They all return void, so there will be no error handling. The first parameter for every command is always the command buffer to record the command to. The second parameter specifies the details of the render pass we've just provided. The final parameter controls how the drawing commands within the render pass will be provided. The other option is for when using SECONDARY buffers.

			// Binding the graphics pipeline (to the command buffer)
			vkCmdBindPipeline(commandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, graphicsPipeline);	// The second parameter specifies if the pipeline object is a graphics or compute pipeline.

			VkBuffer vertexBuffers[] = { vertexBuffer };
			VkDeviceSize offsets[] = { 0 };
			vkCmdBindVertexBuffers(commandBuffers[i], 0, 1, vertexBuffers, offsets);	// The vkCmdBindVertexBuffers function is used to bind vertex buffers to bindings. he first two parameters, besides the command buffer, specify the offset and number of bindings we're going to specify vertex buffers for. The last two parameters specify the array of vertex buffers to bind and the byte offsets to start reading vertex data from.

			vkCmdBindIndexBuffer(commandBuffers[i], indexBuffer, 0, VK_INDEX_TYPE_UINT32);	// An index buffer is bound with vkCmdBindIndexBuffer which has the index buffer, a byte offset into it, and the type of index data as parameters.

			vkCmdBindDescriptorSets(commandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, pipelineLayout, 0, 1, &descriptorSet, 0, nullptr);	// Binds the descriptor set to the descriptors in the shader. Unlike vertex and index buffers, descriptor sets are not unique to graphics pipelines. Therefore we need to specify if we want to bind descriptor sets to the graphics or compute pipeline. The next parameter is the layout that the descriptors are based on. The next three parameters specify the index of the first descriptor set, the number of sets to bind, and the array of sets to bind.

			// Drawing a triangle (without index buffer). Params: vertex count, instance count (Instancing, or instanced rendering, is a way of executing the same drawing commands many times in a row, with each producing a slightly different result.), first vertex (Used as an offset into the vertex buffer and defines the lowest value of vertex indices), first instance (used as an offset for instance rendering and specifies the value of the first instance):
			//vkCmdDraw(commandBuffers[i], static_cast<uint32_t>(vertices.size()), 1, 0, 0);	// Note how the vertex count is the number of vertices in the buffer.

			// Drawing a rectangle using index buffer:
			vkCmdDrawIndexed(commandBuffers[i], static_cast<uint32_t>(indices.size()), 1, 0, 0, 0);	// The second to last parameter specifies an offset to add to the indices in the index buffer. The final parameter specifies an offset for instancing, which we're not using.

			// Finishing the render pass
			vkCmdEndRenderPass(commandBuffers[i]);

			// Finish recording the command buffer
			if (vkEndCommandBuffer(commandBuffers[i]) != VK_SUCCESS)
				throw std::runtime_error("Failed to record command buffer!");
		}
	}

	void createSemaphores() {
		VkSemaphoreCreateInfo semaphoreInfo = {};
		semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

		if (vkCreateSemaphore(device, &semaphoreInfo, nullptr, &imageAvailableSemaphore) != VK_SUCCESS ||
			vkCreateSemaphore(device, &semaphoreInfo, nullptr, &renderFinishedSemaphore) != VK_SUCCESS)
			throw std::runtime_error("failed to create semaphores!");
	}

	void drawFrame() {		// Displays triangle on screen. Asynchronously does 3 things: 1. Acquires an image from the swap chain. 2. Executes the command buffer with that image as the attachment in the framebuffer. 3. Returns the image to the swap chain for presentation. However we need them to execute in order. So we must use fences or semaphores. The difference is that the state of fences can be accessed from your program using calls like vkWaitForFences and semaphores cannot be. Fences are mainly designed to synchronize your application itself with rendering operation, whereas semaphores are used to synchronize operations within or across command queues. We want to synchronize the queue operations of draw commands and presentation, which makes semaphores the best fit. We need 2 semaphores cuz there are 3 ops.
							// Acquiring image from swap chain
		uint32_t imageIndex;
		VkResult result = vkAcquireNextImageKHR(device, swapChain, std::numeric_limits<uint64_t>::max(), imageAvailableSemaphore, VK_NULL_HANDLE, &imageIndex); // The third parameter specifies a timeout in nanoseconds for an image to become available. Using the maximum value of a 64 bit unsigned integer disables the timeout. The next two parameters specify synchronization objects that are to be signaled when the presentation engine is finished using the image. That's the point in time where we can start drawing to it. It is possible to specify a semaphore, fence or both. We're going to use our imageAvailableSemaphore for that purpose here. The last parameter specifies a variable to output the index of the swap chain image that has become available. The index refers to the VkImage in our swapChainImages array. We're going to use that index to pick the right command buffer. This fn failing does not necc. mean the program should terminate. The function returns VK_ERROR_OUT_OF_DATE_KHR if the swap chain has become incompatible with the surface or VK_SUBOPTIMAL_KHR if the swapchain can still be used but the properties are no longer matched exactly. For example, the platform may be simply resizing the image to fit the window now.
		if (result == VK_ERROR_OUT_OF_DATE_KHR) {
			recreateSwapChain();
			return;	// We recreate and try again in the next frame. We could have done this if it were suboptimal too but here we consider that still succcess.
		}
		else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)	// It's like a hack to check for the same condition. Like if for some reason we still got here even though we also had the if statement to be true...
			throw std::runtime_error("Failed to acquire swap chain image!");

		// Submitting command buffer
		VkSubmitInfo submitInfo = {};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		VkSemaphore waitSemaphores[] = { imageAvailableSemaphore };
		VkPipelineStageFlags waitStages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
		submitInfo.waitSemaphoreCount = 1;
		submitInfo.pWaitSemaphores = waitSemaphores;	// Which semaphores to wait on before execution begins
		submitInfo.pWaitDstStageMask = waitStages;		// In which stages of the pipeline to wait. We want to wait with writing colors to the image until it's available, so we're specifying the stage of the graphics pipeline that writes to the color attachment.
		submitInfo.commandBufferCount = 1;
		submitInfo.pCommandBuffers = &commandBuffers[imageIndex];	// Which command buffer to actually submit for execution.
		VkSemaphore signalSemaphores[] = { renderFinishedSemaphore };
		submitInfo.signalSemaphoreCount = 1;
		submitInfo.pSignalSemaphores = signalSemaphores;	// Which semaphores to signal once the command buffers have executed
		if (vkQueueSubmit(graphicsQueue, 1, &submitInfo, VK_NULL_HANDLE) != VK_SUCCESS)	// The last parameter references an optional fence that will be signaled when the command buffers finish execution. We're using semaphores for synchronization, so we'll just pass a VK_NULL_HANDLE.
			throw std::runtime_error("Failed to submit draw command buffer!");

		// Presentation. Submitting the result back to the swap chain to have it eventually show up on the screen.
		VkPresentInfoKHR presentInfo = {};
		presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
		presentInfo.waitSemaphoreCount = 1;
		presentInfo.pWaitSemaphores = signalSemaphores;
		VkSwapchainKHR swapChains[] = { swapChain };
		presentInfo.swapchainCount = 1;
		presentInfo.pSwapchains = swapChains;	// The swap chains to present images to.
		presentInfo.pImageIndices = &imageIndex;
		presentInfo.pResults = nullptr; // Optional. Allows you to specify an array of VkResult values to check for every individual swap chain if presentation was successful. It's not necessary if you're only using a single swap chain, because you can simply use the return value of the present function.
		result = vkQueuePresentKHR(presentQueue, &presentInfo);	// The vkQueuePresentKHR function submits the request to present an image to the swap chain. This fn failing does not necc. mean the program should terminate.

		if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR)
			recreateSwapChain();
		else if (result != VK_SUCCESS)
			throw std::runtime_error("Failed to present swap chain image!");

		vkQueueWaitIdle(presentQueue); // Waits until presentation finishes before starting to draw the next frame. Avoids memory leak.
	}

	// Graphics cards can offer different types of memory to allocate from. Each type of memory varies in terms of allowed operations and performance characteristics. We need to combine the requirements of the vertex buffer and our own application requirements to find the right type of memory to use.
	uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) {
		VkPhysicalDeviceMemoryProperties memProperties;	// The VkPhysicalDeviceMemoryProperties structure has two arrays memoryTypes and memoryHeaps. Memory heaps are distinct memory resources like dedicated VRAM and swap space in RAM for when VRAM runs out. The different types of memory exist within these heaps. Right now we'll only concern ourselves with the type of memory and not the heap it comes from.
		vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProperties);	// Retrieves available memory types
		for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++)
			if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties)	// The typeFilter parameter will be used to specify the bit field of memory types that are suitable. As for the second thing we check for: we're not just interested in a memory type that is suitable for the vertex buffer. We also need to be able to write our vertex data to that memory. The memoryTypes array consists of VkMemoryType structs that specify the heap and properties of each type of memory. The properties define special features of the memory, like being able to map it so we can write to it from the CPU.
				return i;
		throw std::runtime_error("Failed to find suitable memory type!");
	}

	void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory) {
		VkBufferCreateInfo bufferInfo = {};
		bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		bufferInfo.size = size;	// Size of the buffer in bytes
		bufferInfo.usage = usage;		// For which purposes the data in the buffer is going to be used. It is possible to specify multiple purposes using a bitwise or.
		bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;			// The buffer will only be used from the graphics queue, so we can stick to exclusive access.
																	// There's also a flags param used when buffer memory is sparse.

		if (vkCreateBuffer(device, &bufferInfo, nullptr, &buffer) != VK_SUCCESS)
			throw std::runtime_error("Failed to create buffer!");

		// The buffer has been created but it has no memory assigned it it. We use kGetBufferMemoryRequirements() to query how much memory it needs.
		VkMemoryRequirements memRequirements;	// This struct holds size (of memory in bytes) which may differ from bufferInfo.size, alginment which is the offset in bytes where the buffer begins in its memory region (depends on bufferInfo.usage and bufferInfo.flags), memoryTypeBits which is a bit field of the memory types we can use (A bit field is a data structure used in computer programming. It consists of a number of adjacent computer memory locations which have been allocated to hold a sequence of bits, stored so that any single bit or group of bits within the set can be addressed.)
		vkGetBufferMemoryRequirements(device, buffer, &memRequirements);

		VkMemoryAllocateInfo allocInfo = {};
		allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		allocInfo.allocationSize = memRequirements.size;
		allocInfo.memoryTypeIndex = findMemoryType(memRequirements.memoryTypeBits, properties);	// We need properties which allows the memory to be mapped and written to etc. The host coherent bit is used to avoid explicit flushing of memory actually, it's a response to problems caused on mapping memory due to caching etc.

		if (vkAllocateMemory(device, &allocInfo, nullptr, &bufferMemory) != VK_SUCCESS)
			throw std::runtime_error("Failed to allocate buffer memory!");

		// If memory allocation was successful, then we can now associate this memory with the buffer:
		vkBindBufferMemory(device, buffer, bufferMemory, 0);	// The fourth parameter is the offset within the region of memory. Since this memory is allocated specifically for this the vertex buffer, the offset is simply 0. If the offset is non-zero, then it is required to be divisible by memRequirements.alignment.
	}

	void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size) {
		// Memory transfer operations are executed using command buffers, just like drawing commands. Therefore we must first allocate a temporary command buffer. You may wish to create a separate command pool for these kinds of short-lived buffers, because the implementation may be able to apply memory allocation optimizations. You should use the VK_COMMAND_POOL_CREATE_TRANSIENT_BIT flag during command pool generation in that case.
		VkCommandBuffer commandBuffer = beginSingleTimeCommands();

		VkBufferCopy copyRegion = {};
		copyRegion.size = size;
		vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, 1, &copyRegion);

		endSingleTimeCommands(commandBuffer);
	}

	void loadModel() {	// An OBJ file consists of positions, normals, texture coordinates and faces. Compile in Release mode for fast model loading.
		tinyobj::attrib_t attrib;	// The attrib container holds all of the positions, normals and texture coordinates in its attrib.vertices, attrib.normals and attrib.texcoords vectors.
		std::vector<tinyobj::shape_t> shapes;	// The shapes container contains all of the separate objects and their faces. Each face consists of an array of vertices, and each vertex contains the indices of the position, normal and texture coordinate attributes. OBJ models can also define a material and texture per face, but we will be ignoring those.
		std::vector<tinyobj::material_t> materials;
		std::string err;

		if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &err, MODEL_PATH.c_str()))	// LoadObj() by default triangulates any non-triangle faces. This is ideal since this program can only draw triangles.
			throw std::runtime_error(err);	// The err string contains errors and warnings that occurred while loading the file, like a missing material definition.

		std::unordered_map<Vertex, uint32_t> uniqueVertices = {};	// A standard way to implement deduplicating vertex data is to use a map or unordered_map to keep track of the unique vertices and respective indices.

		// Combining all shapes to a single model
		for (const auto& shape : shapes)
			for (const auto& index : shape.mesh.indices) {
				Vertex vertex = {};
				vertex.pos = {
					attrib.vertices[3 * index.vertex_index + 0],	// The attrib.vertices array is an array of float values instead of something like glm::vec3, so you need to multiply the index by 3. Similarly, there are two texture coordinate components per entry. The offsets of 0, 1 and 2 are used to access the X, Y and Z components, or the U and V components in the case of texture coordinates.
					attrib.vertices[3 * index.vertex_index + 1],
					attrib.vertices[3 * index.vertex_index + 2]
				};

				vertex.texCoord = {
					attrib.texcoords[2 * index.texcoord_index + 0],
					1.0f - attrib.texcoords[2 * index.texcoord_index + 1]	// We need to flip the sign by minusing from 1.0f because he origin of texture coordinates in Vulkan is the top-left corner, whereas the OBJ format assumes the bottom-left corner.
				};

				vertex.color = { 1.0f, 1.0f, 1.0f };

				//  The vertices vector contains a lot of duplicated vertex data, because many vertices are included in multiple triangles. We should keep only the unique vertices and use the index buffer to reuse them whenever they come up.
				if (uniqueVertices.count(vertex) == 0) {	// Every time we read a vertex from the OBJ file, we check if we've already seen a vertex with the exact same position and texture coordinates before. If not, we add it to vertices and store its index in the uniqueVertices container. After that we add the index of the new vertex to indices. If we've seen the exact same vertex before, then we look up its index in uniqueVertices and store that index in indices.
					uniqueVertices[vertex] = static_cast<uint32_t>(vertices.size());	// Using a user-defined type like our Vertex struct as key in a hash table requires us to implement two functions: equality test and hash calculation.
					vertices.push_back(vertex);	// vertices is the class member in which we are storing the vertices.
				}
				indices.push_back(uniqueVertices[vertex]);	// indices is the class member where we are storing the indices.
			}
	}

	void createVertexBuffer() {
		VkDeviceSize bufferSize = sizeof(vertices[0]) * vertices.size();

		VkBuffer stagingBuffer; // The staging buffer is in CPU accessible memory to upload the data from the vertex array to and this will pass it to the main vertex buffer. The reason we are using this is because it can have a diff. flag and the other buffer will have a diff. flag, they will be suited for their respective tasks and it will be optimal.
		VkDeviceMemory stagingBufferMemory;
		// Creating the staging buffer
		createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);

		// Copy verted data to buffer. This is done by mapping the buffer memory into CPU accessible memory with vkMapMemory.
		void* data;
		vkMapMemory(device, stagingBufferMemory, 0, bufferSize, 0, &data);	// This function allows us to access a region of the specified memory resource defined by an offset and size. The offset and size here are 0 and bufferInfo.size, respectively. It is also possible to specify the special value VK_WHOLE_SIZE to map all of the memory. The second to last parameter can be used to specify flags, but there aren't any available yet in the current API. It must be set to the value 0. The last parameter specifies the output for the pointer to the mapped memory.
		memcpy(data, vertices.data(), (size_t)bufferSize);	// memcpy the vertex data to the mapped memory
		vkUnmapMemory(device, stagingBufferMemory); // Unmapping

													// Creating the actual vertex buffer
		createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, vertexBuffer, vertexBufferMemory);	// Note how the flags are diff. for this buffer and the other one. VK_BUFFER_USAGE_TRANSFER_SRC_BIT: Buffer can be used as source in a memory transfer operation. VK_BUFFER_USAGE_TRANSFER_DST_BIT: Buffer can be used as destination in a memory transfer operation.

		copyBuffer(stagingBuffer, vertexBuffer, bufferSize);

		vkDestroyBuffer(device, stagingBuffer, nullptr);
		vkFreeMemory(device, stagingBufferMemory, nullptr);
	}

	void createIndexBuffer() {
		VkDeviceSize bufferSize = sizeof(indices[0]) * indices.size();	// indices.size() is the size of the index type, ie either uint16_t or uint32_t.

																		// We need a staging buffer again.
		VkBuffer stagingBuffer;
		VkDeviceMemory stagingBufferMemory;
		createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);

		void* data;
		vkMapMemory(device, stagingBufferMemory, 0, bufferSize, 0, &data);
		memcpy(data, indices.data(), (size_t)bufferSize);
		vkUnmapMemory(device, stagingBufferMemory);

		createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, indexBuffer, indexBufferMemory);	// VK_BUFFER_USAGE_INDEX_BUFFER_BIT instead of VK_BUFFER_USAGE_VERTEX_BUFFER_BIT signifies it's an index buffer.

		copyBuffer(stagingBuffer, indexBuffer, bufferSize);

		vkDestroyBuffer(device, stagingBuffer, nullptr);
		vkFreeMemory(device, stagingBufferMemory, nullptr);
	}

	void createUniformBuffer() {
		VkDeviceSize bufferSize = sizeof(UniformBufferObject);
		createBuffer(bufferSize, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, uniformBuffer, uniformBufferMemory);
	}

	void createDescriptorPool() { // A descriptor set actually specifies a VkBuffer resource to bind to the uniform buffer descriptor. Descriptor sets can't be created directly, they must be allocated from a pool like command buffers that's why we need this fn.
		// We first need to describe which descriptor types our descriptor sets are going to contain and how many of them, using VkDescriptorPoolSize structures:
		std::array<VkDescriptorPoolSize, 2> poolSizes = {};
		poolSizes[0].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		poolSizes[0].descriptorCount = 1;
		poolSizes[1].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		poolSizes[1].descriptorCount = 1;

		VkDescriptorPoolCreateInfo poolInfo = {};
		poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		poolInfo.poolSizeCount = static_cast<uint32_t>(poolSizes.size());
		poolInfo.pPoolSizes = poolSizes.data();
		poolInfo.maxSets = 1;	// Max no. of descriptor sets
		// Optional .flags too

		if (vkCreateDescriptorPool(device, &poolInfo, nullptr, &descriptorPool) != VK_SUCCESS)
			throw std::runtime_error("Failed to create descriptor pool!");
	}

	void createDescriptorSet() {
		VkDescriptorSetLayout layouts[] = { descriptorSetLayout };
		VkDescriptorSetAllocateInfo allocInfo = {};
		allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
		allocInfo.descriptorPool = descriptorPool;
		allocInfo.descriptorSetCount = 1;
		allocInfo.pSetLayouts = layouts;

		if (vkAllocateDescriptorSets(device, &allocInfo, &descriptorSet) != VK_SUCCESS) // You don't need to explicitly clean up descriptor sets, because they will be automatically freed when the descriptor pool is destroyed.
			throw std::runtime_error("Failed to allocate descriptor set!");

		// The descriptor set has been allocated now, but the descriptors within still need to be configured.Descriptors that refer to buffers, like our uniform buffer descriptor, are configured with a VkDescriptorBufferInfo struct.This structure specifies the buffer and the region within it that contains the data for the descriptor:
		VkDescriptorBufferInfo bufferInfo = {};
		bufferInfo.buffer = uniformBuffer;
		bufferInfo.offset = 0;
		bufferInfo.range = sizeof(UniformBufferObject);

		// The resources for a combined image sampler structure must be specified in a VkDescriptorImageInfo struct, just like the buffer resource for a uniform buffer descriptor is specified in a VkDescriptorBufferInfo struct.
		VkDescriptorImageInfo imageInfo = {};
		imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
		imageInfo.imageView = textureImageView;
		imageInfo.sampler = textureSampler;

		// Used to update configuaration of descriptors:
		std::array<VkWriteDescriptorSet, 2> descriptorWrites = {};

		descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		descriptorWrites[0].dstSet = descriptorSet;
		descriptorWrites[0].dstBinding = 0;
		descriptorWrites[0].dstArrayElement = 0;
		descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		descriptorWrites[0].descriptorCount = 1;
		descriptorWrites[0].pBufferInfo = &bufferInfo;	// The pBufferInfo field is used for descriptors that refer to buffer data, pImageInfo is used for descriptors that refer to image data, and pTexelBufferView is used for descriptors that refer to buffer views. Our descriptor is based on buffers, so we're using pBufferInfo.

		descriptorWrites[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		descriptorWrites[1].dstSet = descriptorSet;
		descriptorWrites[1].dstBinding = 1;
		descriptorWrites[1].dstArrayElement = 0;
		descriptorWrites[1].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		descriptorWrites[1].descriptorCount = 1;
		descriptorWrites[1].pImageInfo = &imageInfo;

		vkUpdateDescriptorSets(device, static_cast<uint32_t>(descriptorWrites.size()), descriptorWrites.data(), 0, nullptr);
	}

	void updateUniformBuffer() {	// Updates the uniform buffer with a new transformation every frame. In our case it will create a spin effect.
		static auto startTime = std::chrono::high_resolution_clock::now();

		auto currentTime = std::chrono::high_resolution_clock::now();
		float time = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();

		// We will now define the model, view and projection transformations in the uniform buffer object.
		UniformBufferObject ubo = {};
		// The model rotation will be a simple rotation around the Z-axis using the time variable:
		ubo.model = glm::rotate(glm::mat4(1.0f), time * glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));	// The glm::rotate function takes an existing transformation, rotation angle and rotation axis as parameters. The glm::mat4(1.0f) constructor returns an identity matrix. Using a rotation angle of time * glm::radians(90.0f) accomplishes the purpose of rotation 90 degrees per second.
		ubo.view = glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));	// For the view transformation we just look at the geometry from above at a 45 degree angle. The glm::lookAt function takes the eye position, center position and up axis as parameters.
		ubo.proj = glm::perspective(glm::radians(45.0f), swapChainExtent.width / (float)swapChainExtent.height, 0.1f, 10.0f);	// 45 degree vertical field-of-view. The other parameters are the aspect ratio, near and far view planes. It is important to use the current swap chain extent to calculate the aspect ratio to take into account the new width and height of the window after a resize.
		ubo.proj[1][1] *= -1; // GLM was originally designed for OpenGL, where the Y coordinate of the clip coordinates is inverted. The easiest way to compensate for that is to flip the sign on the scaling factor of the Y axis in the projection matrix. If you don't do this, then the image will be rendered upside down.

							  // All of the transformations are defined now, so we can copy the data in the uniform buffer object to the uniform buffer. Note no staging buffer here:
		void* data;
		vkMapMemory(device, uniformBufferMemory, 0, sizeof(ubo), 0, &data);
		memcpy(data, &ubo, sizeof(ubo));
		vkUnmapMemory(device, uniformBufferMemory);
	}

	void recreateSwapChain() {	// It is possible for the window surface to change such that the swap chain is no longer compatible with it. One of the reasons that could cause this to happen is the size of the window changing. We have to catch these events and recreate the swap chain.
		vkDeviceWaitIdle(device);	// We call this because we shouldn't touch resources still in use.

		cleanupSwapChain();

		// All the things below need to be recreated due to dependencies.
		createSwapChain();
		createImageViews();
		createRenderPass();
		createGraphicsPipeline();
		createDepthResources();
		createFramebuffers();
		createCommandBuffers();
	}

	void initVulkan() {
		createInstance();
		setupDebugCallback();
		createSurface();	// // Needs to be called right after the instance is created that's why it's before the other methods.
		pickPhysicalDevice();
		createLogicalDevice();
		createSwapChain();
		createImageViews();
		createRenderPass();
		createDescriptorSetLayout();
		createGraphicsPipeline();
		createCommandPool();
		createDepthResources();
		createFramebuffers();
		createTextureImage();
		createTextureImageView();
		createTextureSampler();
		loadModel();
		createVertexBuffer();
		createIndexBuffer();
		createUniformBuffer();
		createDescriptorPool();
		createDescriptorSet();
		createCommandBuffers();
		createSemaphores();
	}

	void mainLoop() {
		while (!glfwWindowShouldClose(window)) {	// The event loop. App runs until window closes. Events that are checked for are button presses etc.
			glfwPollEvents();
			updateUniformBuffer();
			drawFrame();
		}
		vkDeviceWaitIdle(device);	// This waits for devices to finish all operations before we exit this method. Because we use some async calls we need this.
	}

	void cleanupSwapChain() {	// Cleanup code for all objects recreated as part of swapchain refresh
		vkDestroyImageView(device, depthImageView, nullptr);
		vkDestroyImage(device, depthImage, nullptr);
		vkFreeMemory(device, depthImageMemory, nullptr);
		for (size_t i = 0; i < swapChainFramebuffers.size(); i++)
			vkDestroyFramebuffer(device, swapChainFramebuffers[i], nullptr);	// The nullptr is an optional allocator callback.
		vkFreeCommandBuffers(device, commandPool, static_cast<uint32_t>(commandBuffers.size()), commandBuffers.data());
		vkDestroyPipeline(device, graphicsPipeline, nullptr);
		vkDestroyPipelineLayout(device, pipelineLayout, nullptr);
		vkDestroyRenderPass(device, renderPass, nullptr);
		for (size_t i = 0; i < swapChainImageViews.size(); i++)
			vkDestroyImageView(device, swapChainImageViews[i], nullptr);
		vkDestroySwapchainKHR(device, swapChain, nullptr);
	}


	void cleanup() {		// Every Vulkan object that we create needs to be explicitly destroyed when we no longer need it. In modern C++ code it is possible to do automatic resource management through the utilities in the <memory> header but using that would defeat the purpose of Vulkan.
		cleanupSwapChain();
		vkDestroySampler(device, textureSampler, nullptr);
		vkDestroyImageView(device, textureImageView, nullptr);
		vkDestroyImage(device, textureImage, nullptr);
		vkFreeMemory(device, textureImageMemory, nullptr);
		vkDestroyDescriptorPool(device, descriptorPool, nullptr);
		vkDestroyDescriptorSetLayout(device, descriptorSetLayout, nullptr);
		vkDestroyBuffer(device, uniformBuffer, nullptr);
		vkFreeMemory(device, uniformBufferMemory, nullptr);
		vkDestroyBuffer(device, indexBuffer, nullptr);
		vkFreeMemory(device, indexBufferMemory, nullptr);
		vkDestroyBuffer(device, vertexBuffer, nullptr);
		vkFreeMemory(device, vertexBufferMemory, nullptr);
		vkDestroySemaphore(device, renderFinishedSemaphore, nullptr);
		vkDestroySemaphore(device, imageAvailableSemaphore, nullptr);
		vkDestroyCommandPool(device, commandPool, nullptr);
		vkDestroyDevice(device, nullptr);
		DestroyDebugReportCallbackEXT(instance, callback, nullptr);
		vkDestroySurfaceKHR(instance, surface, nullptr);
		vkDestroyInstance(instance, nullptr);
		glfwDestroyWindow(window);
		glfwTerminate();
	}
};

int main() {
	VulkanApp app;

	try {
		app.run();
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}