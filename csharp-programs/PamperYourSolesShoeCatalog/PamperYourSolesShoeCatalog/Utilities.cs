/// <file>
/// <author>hb20007</author>
/// <datecreated>2016-10-24</datecreated>
/// <summary>
/// Contains the class Utilities which has useful static methods
/// </summary>
/// </file>

namespace PamperYourSolesShoeCatalog
{
    static class Utilities
    {
        /// <summary>
        /// Performs the modulo operation
        /// </summary>
        /// <param name="m">An integer</param>
        /// <param name="n">Another integer</param>
        /// <returns></returns>
        internal static int mod (int m, int n)
        {
            return (m % n + n) % n;
        }

        /// <summary>
        /// Returns the index of the next element in an array given the current index and the size of the array. If it is the last element, it returns the index of the first element
        /// </summary>
        /// <param name="currentIndex">The current index in the array</param>
        /// <param name="arraySize">The number of elements in the array</param>
        /// <returns></returns>
        internal static int nextIndex(int currentIndex, int arraySize)
        {
            return ++currentIndex % arraySize;
        }

        /// <summary>
        /// Returns the index of the previous element in an array given the current index and the size of the array. If it is the first element, it returns the index of the last element
        /// </summary>
        /// <param name="currentIndex">The current index in the array</param>
        /// <param name="arraySize">The number of elements in the array</param>
        /// <returns></returns>
        internal static int previousIndex(int currentIndex, int arraySize)
        {
            return mod(--currentIndex, arraySize);
        }
    }
}
