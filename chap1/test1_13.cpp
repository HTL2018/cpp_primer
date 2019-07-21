/*
#include <iostream>
int main()
{
        int sum = 0;
	for(int val=50; val<=100; ++val)
	{
	sum += val;
	} 
        std::cout << " Sum of 50 to 100 is " << sum << std::endl;
        return 0;
}
*/

/*
#include <iostream>
int main()
{
	for(int val=10; val>=0; --val)
        {
               
                std::cout << val << std::endl;
        }

        return 0;
}
*/

#include <iostream>
int main()
{
        std::cout << "Please input two integer:" << std::endl;
        int v1=0, v2=0, v3=0;
        std::cin >> v1 >> v2;
        if (v1 == v2)
                {}
        else
                {
                        if (v1 < v2)
                                {v3 = v1;
                                v1 = v2;
                                v2 = v3;
                               for(;v1>v2;)
                                        {
                                     v1--; 
                                     if(v1 != v2){   std::cout << v1 << std::endl;}
                                        }
                                }
                        else

                                {

                                        for(;v1>v2;)
                                        {
                                        v1--;
                                        if(v1 != v2){std::cout << v1 << std::endl;}
                                        }
                                }

                }


        return 0;
}
