#include <stdio.h>
#include <stdlib.h>
#include <iostream>

namespace Prvni
{
    
class Zasobnik
{
private :
    const int kapacita;
    int pocet;
    int *data;
     
     
    
    public:

    Zasobnik(int kapacita) : kapacita(kapacita), pocet(0), data(NULL)
    {
      
        data = new int[kapacita];
        printf("sizeof kapacita je %d\n",sizeof(kapacita));
		printf("sizeof data je %d\n",sizeof(data));
        
        
    }        
    void tlac(int nevim){   
        data++;
		printf("  data++ %d  ",data );
        if(pocet<kapacita){
        *data = nevim;
		printf("  *data  %d ",*data);
        pocet++;
        }
        else
        std::cout <<"Neni misto blbe." << std::endl;
        
    }
    
    int pop(){   
      if(pocet>0)
        {
        int dat = *data;
        data--;
        pocet--;
        return dat;
        }
        else
        {
            std::cout <<"Nic nemam. Nemame nic na zasobniku."<< std::endl;
            return -1;
        }
        /*pocet++;
        if(pocet!=kapacita){
            data++;
        
        
        }*/
    }
    
};
}


int main()
{
    Prvni::Zasobnik z(5);
    z.tlac(4);
    z.tlac(5);
    z.tlac(8);
    z.tlac(2);
    z.tlac(1);
    printf("\n");
    printf("Pop - %d \n",z.pop());
    z.tlac(12);
    printf("\n");
    printf("Pop - %d \n",z.pop());
    printf("Pop - %d \n",z.pop());
    printf("Pop - %d \n",z.pop());
    printf("Pop - %d \n",z.pop());
    printf("Pop - %d \n",z.pop());
    printf("Pop - %d \n",z.pop());
    z.tlac(25);
    printf("Pop - %d \n",z.pop());
      printf("char %d\n",sizeof(char)); 
    printf("int %d\n",sizeof(int)); 
    printf("float %d\n",sizeof(float)); 
    printf("double %d", sizeof(double)); 
        
  
    return 0;
}
