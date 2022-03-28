#include "../includes/header.hpp"
#include <iostream>

int		main(int argc, char** argv, char** envp){
	t_vars	vars;

	vars.argc = argc;
	vars.argv = argv;
	vars.envp = envp;

	// check args
	if(argc < 3){
		write(2, "argv[1] = src_ip; argv[2] = src_port", strlen("argv[1] = src_ip; argv[2] = src_port"));
		exit(1);
	}

	// create src_socket
	vars.src_sock_fd = socket(AF_LOCAL, SOCK_DGRAM, 0);
	if(vars.src_sock_fd < 0){
		write(2, "Fatal error_1\n", strlen("Fatal error_1\n"));
		exit(1);
	}

	// insert src info
	bzero(&vars.src_addr, sizeof(vars.src_addr));
	bzero(&vars.buff, sizeof(vars.buff));

	std::cout << argv[1] << std::endl;
	std::cout << argv[2] << std::endl;

	vars.src_addr.sin_family = AF_LOCAL;
	vars.src_addr.sin_port = htons(atoi(argv[2]));
	vars.src_addr.sin_addr.s_addr = inet_addr(argv[1]);

	// add adress to socket
	int result = 0;
	result = bind(vars.src_sock_fd, (struct sockaddr *)&vars.src_addr, sizeof(vars.src_addr));
	if(result < 0){
		printf("Error = %s\n", strerror(errno));
		write(2, "Fatal error_2\n", strlen("Fatal error_2\n"));
		exit(1);
	}

	// socklen_t len = sizeof(vars.src_addr);
	// result = connect(vars.src_sock_fd, (const struct sockaddr *)&(vars.src_sock_fd), len);
	// if(result < 0){
	// 	printf("Error = %s\n", strerror(errno));
	// 	write(2, "Fatal error_3\n", strlen("Fatal error_3\n"));
	// 	exit(1);
	// }

	int ret = 0;
	socklen_t size = sizeof(vars.src_addr);
	while(ret >= 0){
		ret = recvfrom(vars.src_sock_fd, vars.buff, sizeof(vars.buff), 0, (struct sockaddr *)&vars.src_addr, &size);
		// std::cout << recv(vars.src_sock_fd, vars.buff, sizeof(vars.buff), 0) << std::endl;
		std::cout << vars.buff << std::endl;
		bzero(&vars.buff, sizeof(vars.buff));
	}

	return 0;

	// Parsing config file
	// Create epoll
	// Create sockets and add in queue
	// Create socket
	// val ipAddress: InetAddress = InetAddress.getByName("127.0.0.1")
	// val port = 1111
	// val queueLength = 100
	// val server = new ServerSocket(port, queueLength, ipAddress)

	// Create client connections
	// val client = server.accept()

	// Create input and output buffer
	// val in = new BufferedReader(new InputStreamReader(client.getInputStream))
	// val out = new BufferedWriter(new OutputStreamWriter(client.getOutputStream))

	// Read request
	// val message = new ArrayBuffer[String]
	// message.addOne(in.readLine())
	// while (message.apply(message.length - 1).nonEmpty) {
	// 	message.addOne(in.readLine())
	// }
	// println(s"Get message: ${message.mkString("\n")}")

	// Send responce
	// println("fine")
	// out.write("HTTP/1.1 200 OK\n\n")
	// out.flush()
	// println("fine 2")

	// client.close()
	// println("fine 3")
	// in.close()
	// println("fine 4")
	// out.close()
	// println("fine 5")
	// // Cycle for monitoring connections on sockets
//		while (true) {
//			println(s"Cycle iteration")
//			wait(100)
//		}
}