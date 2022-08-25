#pragma once



class MyColor
{
public:
	int a;
	int r;
	int g;
	int b;

	int toIntValue() const { return	(a << 24) + (r << 16) + (g << 8) + b; }

	MyColor(int a, int r, int g, int b) : a(a), r(r), g(g), b(b) {}


	MyColor(int intColorVal)
	{
		b = (intColorVal) & 255;  //  binary mask (0b11111111 = 255)
		g = (intColorVal >> 8) & 255;
		r = (intColorVal >> 16) & 255;
		a = (intColorVal >> 24) & 255;
	}

	static void CouleurRaprochement(MyColor &c, const MyColor &original)
	{
		if (c.a != original.a)
			changeVal(&c.a, original.a);

		if (c.r != original.r)
			changeVal(&c.r, original.r);

		if (c.g != original.g)
			changeVal(&c.g, original.g);

		if (c.b != original.b)
			changeVal(&c.b, original.b);
	}

	static void changeVal(int * colVal, const  int originalVal)
	{
		if (*colVal == originalVal) return;

		if (*colVal > originalVal)
			*colVal -= 1;
		else
			*colVal += 1;
	}


};

