
#include <stdio.h>

#include <mach/mach.h>
#include <servers/bootstrap.h>

struct {
    mach_msg_header_t header;
    char some_text[100];
    char sender[20];
} message;
int main() {

    // Lookup the receiver port using the bootstrap server.
    mach_port_t port;
    kern_return_t kr = bootstrap_look_up(bootstrap_port, "com.example", &port);
    if (kr != KERN_SUCCESS) {
        printf("bootstrap_look_up() failed with code 0x%x\n", kr);
        return 1;
    }
    printf("bootstrap_look_up() returned port right name %d\n", port);


    // Construct our message.


    message.header.msgh_bits = MACH_MSGH_BITS(MACH_MSG_TYPE_COPY_SEND, 0);
    message.header.msgh_remote_port = port;
    message.header.msgh_local_port = MACH_PORT_NULL;
    printf("sender name: ");
    scanf("%s", message.sender);
    getchar();



    // Send the message.
    while(1){
        printf("sending message to port %d : ", message.header.msgh_remote_port);
        fgets(message.some_text, sizeof(message.some_text), stdin);
        kr = mach_msg(
            &message.header,  // Same as (mach_msg_header_t *) &message.
            MACH_SEND_MSG,    // Options. We're sending a message.
            sizeof(message),  // Size of the message being sent.
            0,                // Size of the buffer for receiving.
            MACH_PORT_NULL,   // A port to receive a message on, if receiving.
            MACH_MSG_TIMEOUT_NONE,
            MACH_PORT_NULL    // Port for the kernel to send notifications about this message to.
        );

        if (kr != KERN_SUCCESS) {
            printf("mach_msg() failed with code 0x%x\n", kr);
            return 1;
        }
        printf("------Sent-------\n");
    }
}

