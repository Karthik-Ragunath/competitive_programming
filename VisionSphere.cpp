#include<bits/stdc++.h>
using namespace std;
#define ll long long int

double returnB(double Xa, double Ya, double Za, double Xb, double Yb, double Zb, double Cx, double Cy, double Cz)
{
	double b = 2 * ((Xb - Xa) * (Xa - Cx) + (Yb - Ya) * (Ya - Cy) + (Zb - Za) * (Za - Cz));
	return b;
}

double returnA(double Xa, double Ya, double Za, double Xb, double Yb, double Zb)
{
	double a = (Xb - Xa) * (Xb - Xa) + (Yb - Ya) * (Yb - Ya) + (Zb - Za) * (Zb - Za);
	return a;
}

double returnC(double Xa, double Ya, double Za, double Cx, double Cy, double Cz, double r)
{
	double c = (Xa - Cx) * (Xa - Cx) + (Ya - Cy) * (Ya - Cy) + (Za - Cz) * (Za - Cz) - (r * r);
	return c;
}

double returnDiscriminant(double Xa, double Ya, double Za, double XbOriginal, double YbOriginal, double ZbOriginal, double Dx, double Dy, double Dz, double Cx, double Cy, double Cz, double r, double offSet, double c)
{
	double Xb = XbOriginal + (offSet) * Dx;
	double Yb = YbOriginal + (offSet) * Dy;
	double Zb = ZbOriginal + (offSet) * Dz;
	double b = returnB(Xa, Ya, Za, Xb, Yb, Zb, Cx, Cy, Cz);
	double a = returnA(Xa, Ya, Za, Xb, Yb, Zb);
	// double c = returnC(Xa, Ya, Za, Cx, Cy, Cz, r);
	double determinant = (b * b) - 4 * a * c;
	return determinant;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll testcases;
	cin >> testcases;
	for(ll k = 0; k < testcases; k++)
	{
		double Xa, Ya, Za, XbOriginal, YbOriginal, ZbOriginal, Dx, Dy, Dz, Cx, Cy, Cz, r;
		cin >> Xa >> Ya >> Za >> XbOriginal >> YbOriginal >> ZbOriginal >> Dx >> Dy >> Dz >> Cx >> Cy >> Cz >> r;
		double c = (Xa - Cx) * (Xa - Cx) + (Ya - Cy) * (Ya - Cy) + (Za - Cz) * (Za - Cz) - (r * r);
		double solution = 0;
		double low = 0;
		double high = 1000000000;
		while(1)
		{
			double mid = (high + low) / (double)2;
			double determinant = returnDiscriminant(Xa, Ya, Za, XbOriginal, YbOriginal, ZbOriginal, Dx, Dy, Dz, Cx, Cy, Cz, r, mid, c);
            cout << "determinant: " << determinant << endl;
            if(determinant == 0)
            {
                solution = mid;
                break;
            }
			if(determinant < 0)
			{
				double newDeterminant = determinant * (double)(-1);
                if(newDeterminant < 0.00001)
                {
                    solution = mid;
                    break;
                }
			}
            else
            {
                if(determinant < 0.00001)
                {
                    solution = mid;
                    break;
                }
            }
            if(determinant < 0)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
		}
        cout.precision(6);
		cout << fixed << solution << endl;
	}
	return 0;
}
