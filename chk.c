char chk_add(char *p, unsigned n)
{
	if (!n)
		return 0;
	return *p + chk_add(p + 1, n - 1);
}

char chk_xor(char *p, unsigned n)
{
	if (!n)
		return 0;
	return *p ^ chk_xor(p + 1, n - 1);
}
