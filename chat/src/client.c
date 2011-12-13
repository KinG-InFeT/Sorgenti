#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//costanti definite
#define PORT 6667		//porta di connessione
#define MAXLINE 10000	//massima portata anti buffer overflow
#define EXIT "exit_chat"

//prototipi di funzione
void print_header( void );
void print_footer( void );
void socket_init( struct sockaddr_in *, int , long int );
void usage( const char * );
void print_error( void );

int main( int argc, char *argv[] ){

	//dichiarazione variabili
	int sd;	//socket description
	int pid;
	struct sockaddr_in server;
	char buff[ MAXLINE ], reply[ MAXLINE ];
   
   //controllo sull'inserimento dei parametri
   if( argc != 2 )
      usage( argv[ 0 ] );
   
   //stampo l'header della chat
   print_header();
   atexit( print_footer );
   
   //creo il socket e controllo se mi da errori
   if( ( sd = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 )
      print_error();
   
   //inizializzo il socket creato
   socket_init( &server, PORT, inet_addr( argv[ 1 ] ) );
   
   //mi connetto al socket del server e controllo se mi da errori
   if( connect( sd, ( struct sockaddr * ) &server, sizeof( server ) ) < 0 )
      print_error();
   
   //trasformo i 2 processi dei socket in 2 identici
   pid = fork();
   
   while( 1 ){
      
      //Blocco attacchi o exploit di Buffer Overflow
      memset( buff, 0x0, strlen( buff ) );		//Setto la memoria allocata
      memset( reply, 0x0, strlen( reply ) );	//Setto la memoria allocata
      
      //controllo se il processo assume valore -1 o 0
      switch( pid ){
      	
      	 //con -1 mi da un'errore quindi stampo un relativo errore	
         case -1:
            print_error();
         break;
         
         //con 0 vado avanti e posso chattare :P
         case 0:
            printf( "> " );
            fgets( buff, sizeof( buff ), stdin );//prelevo la stringa da inviare
            buff[ strlen( buff ) ] = '\0';//termino la stringa con il classico \0
            
            //classico controllo sull'input inserito per evitare Buffer overflow :P
            if( strcmp( buff, EXIT ) == 0 ) {
               close( sd );
               exit( EXIT_SUCCESS );
            }
            
            //ora invio fisicamente la stringa con la send() e controllandola
            if( send( sd, buff, sizeof( buff ), 0 ) < 0 )
               print_error();
         break;
            
            //se non è -1 : errore o 0 : invio allora si sta ricevendo quindi
         default:
         	//ricevo tutto ciò che cè in entrata con recv()
            while( recv( sd, reply, sizeof( reply ), 0 ) > 0 )
               printf( "Server says: %s\n", reply ); //e la stampo semplicemente
            
            while( pid = wait( ( int * ) 0 ) > 0 );//controllo sempre se io stesso voglio inviare o ricevere oppure cè un'errore
         break;
      
      }
   
   }
   
   //chiudo il socket :P
   close( sd );
   return 0;
   
}

//funzione che printa l'header della chat
void print_header() {
char version[10];
	
	strcpy(version, "0.0.1");

   printf( "\n0xChat\n\tBy KinG-InFeT v%s\n\n", version);

}

//funzione che struttura le informazioni per il socket
void socket_init( struct sockaddr_in *conn, int port, long int ip ) {

   conn->sin_family = AF_INET;
   conn->sin_port = htons( port );
   conn->sin_addr.s_addr = ip;

}

//funzione per l'errore da printare se non si passano gli adeguati parametri
void usage( const char *argument ) {

   printf( "\n\nUsage: %s <IP> \n\n", argument );
   exit( EXIT_FAILURE );

}

//la fine della chat xd
void print_footer() {

   printf( "\nCiao %s! FINE!\n", getenv( "USER" ) );

}

//printing dell'errore nel caso il socket ne rilascia uno :S
void print_error() {

   perror( "ERROR!" );
   exit( EXIT_FAILURE );

}
