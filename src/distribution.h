#pragma once

inline static float GetDistribution(int64 nHeight){
	float nSubsidy = 50.0f;
	
	if(nHeight > 17500)
	{
		nSubsidy = 41.60f;
	}
	else if(nHeight > 35000)
	{
		nSubsidy = 36.40f;
	}
	else if(nHeight > 52500)
	{
		nSubsidy = 32.76f;
	}
	else if(nHeight > 70000)
	{
		nSubsidy = 30.03f;
	}
	else if(nHeight > 87500)
	{
		nSubsidy = 27.885f;
	}
	else if(nHeight > 105000)
	{
		nSubsidy = 24.40f;
	}
	else if(nHeight > 122500)
	{
		nSubsidy = 21.69f;
	}
	else if(nHeight > 140000)
	{
		nSubsidy = 19.52f;
	}
	else if(nHeight > 157500)
	{
		nSubsidy = 17.75f;
	}
	else if(nHeight > 175000)
	{
		nSubsidy = 16.27f;
	}
	else if(nHeight > 192500)
	{
		nSubsidy = 15.02f;
	}
	else if(nHeight > 210000)
	{
		nSubsidy = 13.02f;
	}
	else if(nHeight > 227500)
	{
		nSubsidy = 11.49f;
	}
	else if(nHeight > 245000)
	{
		nSubsidy = 10.28f;
	}
	else if(nHeight > 262500)
	{
		nSubsidy = 9.30f;
	}
	else if(nHeight > 280000)
	{
		nSubsidy = 8.49f;
	}
	else if(nHeight > 297500)
	{
		nSubsidy = 7.81f;
	}
	else if(nHeight > 315000)
	{
		nSubsidy = 6.51f;
	}
	else if(nHeight > 332500)
	{
		nSubsidy = 5.45f;
	}
	else if(nHeight > 350000)
	{
		nSubsidy = 4.59f;
	}
	else if(nHeight > 367500)
	{
		nSubsidy = 3.88f;
	}
	else if(nHeight > 385000)
	{
		nSubsidy = 3.29f;
	}
	else if(nHeight > 402500)
	{
		nSubsidy = 2.8f;
	}
	else if(nHeight > 420000)
	{
		nSubsidy = 2.53f;
	}
	else if(nHeight > 437500)
	{
		nSubsidy = 2.31f;
	}
	else if(nHeight > 455000)
	{
		nSubsidy = 2.13f;
	}
	else if(nHeight > 472500)
	{
		nSubsidy = 1.97f;
	}
	else if(nHeight > 490000)
	{
		nSubsidy = 1.83f;
	}
	else if(nHeight > 507500)
	{
		nSubsidy = 1.72f;
	}
	else if(nHeight > 525000)
	{
		nSubsidy = 1.62f;
	}
	else if(nHeight > 542500)
	{
		nSubsidy = 1.53f;
	}
	else if(nHeight > 560000)
	{
		nSubsidy = 1.45f;
	}
	else if(nHeight > 577500)
	{
		nSubsidy = 1.38f;
	}
	else if(nHeight > 595000)
	{
		nSubsidy = 1.31f;
	}
	else if(nHeight > 612500)
	{
		nSubsidy = 1.25f;
	}
	else if(nHeight > 612500)
	{
		nSubsidy = 2.0f;
	}
	
	return nSubsidy;
}
