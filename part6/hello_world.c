#include <fcgi_stdio.h>
#include <stdlib.h>

int main(void) {
    while (FCGI_Accept() >= 0) {
        printf("Content-type: text/html\r\n"
               "\r\n"
               "<html>\n"
               "<body>\n"
               "<h1>Hello World!</h1>\n"
               "</body>\n"
               "</html>\n");
    }
    return 0;
}
