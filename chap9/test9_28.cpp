void insert_str (forward_list<string> &fstr, string &str0, string &str1)
{
    curr = fstr.begin();

    while (curr != fstr.end())
    {
        if (*curr == str0)
        {
            curr = flst.insert_after(curr, str1);
            return;
        }
        else
        {
            ++curr;
        }
    }
    fstr.insert_after(curr , str1);

}
