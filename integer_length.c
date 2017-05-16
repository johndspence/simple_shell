int integer_length(int n)
{
    int i;

    for (i = 0; n <= -1; i++)
    {
        n = n / 10;
    }
    return i;
}
