import java.util.*;
class Dv
{
	private int arr[][];
	private int n;
	private Scanner s;
	private int dist[];
	private int prev[];
	
	public Dv()
	{
		s=new Scanner(System.in);
		System.out.println("enter the size");
		n=s.nextInt();
		arr=new int[n][n];
		
		dist=new int[n];
		prev=new int[n];
		for(int i=0;i<n;i++)
			arr[i][i]=-1;
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				System.out.println("i:"+i+" j:"+j);
				arr[i][j]=s.nextInt();
				arr[j][i]=arr[i][j];
			}
		}
		
	}
	
	public void update(int r,int c,int wt)
	{
		arr[r][c]=wt;
		arr[c][r]=wt;
	}
	void trace(int m)
	{
		if(m==-1) return;
		trace(prev[m]);
		System.out.print(m+" ");
		
	}
	public void reset()
	{
		Arrays.fill(dist,Integer.MAX_VALUE);
		Arrays.fill(prev,-1);
	}
	
	void display()
	{
		for(int i=0;i<n;i++)
			System.out.println(Arrays.toString(arr[i]));
	}
	
	boolean allv(boolean v[])
	{
		for(int i=0;i<n;i++)
        {
            if(v[i]==false)
				return false;
        }
        return true;
	}
	
	void compute(int source)
	{
		System.out.println("SOURCE IS "+source);
		reset();
		dist[source]=0;
		boolean v[]=new boolean[n];
		
		Arrays.fill(v,false);
		while(!allv(v))
		{
			int index=0;
			int min=Integer.MAX_VALUE;
			for(int i=0;i<n;i++)
			{
				if(!v[i] && dist[i]<min)
				{
					index=i;
					min=dist[i];
				}
			
			}
			v[index]=true;
			for(int i=0;i<n;i++)
			{
				if(!v[i] && (arr[i][index]>=0) && ((dist[index]+arr[i][index])<dist[i]))
				{
					dist[i]=dist[index]+arr[i][index];
					prev[i]=index;
				}
			}
			System.out.println("current node is"+index+"\n"+Arrays.toString(dist));
			
		}
		
		System.out.println("Final distance now is"+"\n"+Arrays.toString(dist));
		//System.out.println("parent is"+"\n"+Arrays.toString(prev));
		
		for(int i=0;i<n;i++)
		{
			if(i!=source)
			{
				System.out.print("route to "+i+":");
				trace(i);
				System.out.println("\n");
			}
		}
	}
	
	public static void main(String args[])
	{
		Dv d=new Dv();
		d.display();
		d.compute(0);
		d.update(0,2,1);
		d.compute(0);
		
	}
	
	
	
}