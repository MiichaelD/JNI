public class Parametros
{
 private native int suma(int a, int b);
 private native String pideTexto(String prompt);
 private native int[] sumaArrays (int[]A,int[]B);
 private native int[][] sumaMatrices (int[][] A, int [][] B);
 
 public static void main(String[] args)
	{
	Parametros p = new Parametros();
	System.out.println("3+4="+p.suma(3,4));
	String texto = p.pideTexto("Escriba Texto");
	System.out.println("El texto devuelto es:"+texto);
	
	int[] A = {1,2,3};
	int[] B = {3,2,1};
	int[] C = p.sumaArrays(A,B);
	if (C==null)
		System.out.println("No se pudo hace la suma");
		else
		{
		 System.out.print("La suma de arrays es:");
		 for (int i=0;i<C.length;i++)
			System.out.print(C[i]+" ");
		System.out.println();
			}
	 int [][] M1 = {{2,3},{4,6},{2,4}};
	 int [][] M2 = {{4,3},{0,2},{1,5}};
	 int [][] M3 = p.sumaMatrices(M1,M2);
	 if (M3 == null)
		System.out.println("Fallo la suma");
	 else 
		{
		 System.out.println("La suma es:");
		 for (int i=0;i<M3.length;i++)
			{
			 for (int j=0;j<M3[i].length;j++)
				System.out.print(M3[i][j]+" ");
			 System.out.println();
			}
		}
	}
static{
		System.loadLibrary("Parametros");
		}
}