#include <locale.h>
#include "menu.h"

int main()
{
   setlocale(LC_ALL,"Portuguese");
   exibeOpcoes();
   return 0;
}
