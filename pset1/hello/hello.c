#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string n = get_string ("Enter your first name\n");
    printf("Hello, %s \n", n);
}