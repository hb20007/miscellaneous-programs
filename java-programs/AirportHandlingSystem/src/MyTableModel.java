import javax.swing.table.DefaultTableModel;

public class MyTableModel extends DefaultTableModel{ //I will override 2 methods in order to make my table which inherits this method uneditable in the GUI

	private static final long serialVersionUID = 376330134669153189L; //Serializable class
	
	MyTableModel(Object[][] data,Object[] columns) {
		super(data,columns);
	}
	
	boolean[] columnEditables = new boolean[] {
			false, false, false, false, false, false, false, false //All the columns will be uneditable since the table is not modifable 
		};
		public boolean isCellEditable(int row, int column) {
			return columnEditables[column];
		}
}
