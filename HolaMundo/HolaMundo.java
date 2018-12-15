public class HolaMundo
{
	private native void saluda();
	public static void main (String[] args)
		{
		 new HolaMundo().saluda();
		 }
	static {
			System.loadLibrary("HolaMundo");
			}
}