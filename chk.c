unsigned char chk_add(unsigned char *p, unsigned n)
{
	if (!n)
		return 0;
	return *p + chk_add(p + 1, n - 1);
}

unsigned char chk_xor(unsigned char *p, unsigned n)
{
	if (!n)
		return 0;
	return *p ^ chk_xor(p + 1, n - 1);
}
