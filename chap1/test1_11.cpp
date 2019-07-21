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
				while(v1>v2)
                                        {
                                        v1--;
                                     if(v1 != v2){   std::cout << v1 << std::endl;}
                                        }
				}
			else

				{	
					
        				while(v1>v2)
        				{
					v1--;
                			if(v1 != v2){std::cout << v1 << std::endl;}
					}
				}
				
		}
        

        return 0;
}
