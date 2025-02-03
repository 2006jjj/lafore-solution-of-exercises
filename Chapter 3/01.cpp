bool test4()
{
	Candle candle{ 1.001, 4.4, 5.5, 1.0 };
	return candle.open != candle.close;
	//return candle.is_red();
}
