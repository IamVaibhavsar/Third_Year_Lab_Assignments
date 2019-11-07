
#NAME: VAIBHAV SUDHAKAR BHAVSAR
#TE-B
#ROLL NO: 08
#ASSIGNMENT NO: 10
#PROBLEM STATEMENT:
#Study of any network simulation tools - To create a network with three nodes and establish a
#TCP connection between node 0 and node 1 such that node 0 will send TCP packet to node 2 via node 1


#Create a simulator object
set ns [new Simulator]

#Define different colors for data flows (for NAM)
$ns color 1 Red

#Open the NAM trace file
set nf [open out.nam w]
$ns namtrace-all $nf

# Open the trace file
set f [open tcp.tr w]
$ns trace-all $f

#Define a 'finish' procedure
proc finish {} {
    global ns nf f
    $ns flush-trace
    #Close the NAM trace file
    close $nf
    # Close the trace file
    close $f
    #Execute NAM on the trace file
    exec nam out.nam &
    exit 0
}

#Create three nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

#Create links between the nodes
$ns duplex-link $n0 $n1 1Mb 50ms DropTail
$ns duplex-link $n1 $n2 100Kb 5ms DropTail

#Set Queue Size of link (n1-n2) to 10
$ns queue-limit $n1 $n2 10


#Give node position (for NAM)
$ns duplex-link-op $n0 $n1 orient right
$ns duplex-link-op $n1 $n2 orient right

#Monitor the queue for link (n1-n2). (for NAM)
$ns duplex-link-op $n1 $n2 queuePos 0.5

#Setup a TCP connection
set tcp [new Agent/TCP]
$tcp set class_ 1
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n2 $sink
$ns connect $tcp $sink

#Setup a FTP over TCP connection
set ftp [new Application/FTP]
$ftp attach-agent $tcp

#Start and stop FTP
$ns at 0.5 "$ftp start"
$ns at 50.5 "$ftp stop"

#Call the finish procedure after 51 seconds of simulation time
$ns at 51.0 "finish"

#Run the simulation
$ns run


output=====
cd Desktop/
res@res-HP-280-G2-MT-Legacy:~/Desktop$ ns ns.tcl

=======================

