/*
 * bar = ""
 *
 * for x in range(100):
 *    sys.stdout.write("\r%s -> %s%%" % (bar, x))
 *       time.sleep(0.5)
 *          sys.stdout.flush()
 *             bar = bar + "="
 */

#include <stdio.h>
#include <unistd.h>

int
main(int argc,char **argv)
{
	char bar[101] = { 0 };
	int i;

	char buf[BUFSIZ] = { 0 };

	char load[] = "|\\-/";

	for(i = 0;i <= 100;i++)
	{
		/* sprintf( buf, "\r%s -> %d%%", bar, i ); */
		sprintf( buf, "\r%c - %d%%", load[ i % 4 ], i ); 
		write( 1, buf, strlen(buf)) ;

		usleep( 0.1 * 1000000 );

		fsync( 1 );

		bar[strlen(bar)] = '=';
	}

	putchar('\n');

	return 0;
}

