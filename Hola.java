public class Hola{

	private native void saluda();
	public static void main(String[] arg){
		new Hola().saluda();
	}
	static{
		System.loadLibrary("Hola");
	}

}