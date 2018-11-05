#include <iostream.h>
main()
{

while (char a = getch() != char(27))
{
cout << a <<" - " <<int(a)<<endl;
}

}