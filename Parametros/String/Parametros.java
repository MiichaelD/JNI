public class Parametros
{
 private native int suma(int a, int b);
 private native String pideTexto(String prompt);
 public static void main(String[] args)
	{
	Parametros p = new Parametros();
	String texto = p.pideTexto("Escriba Texto");
	System.out.println("El texto devuelto es:"+texto);
	}
static{
		System.loadLibrary("Parametros");
		}
}