# Console application based on Shapes which displays use of keyed instances

Skeleton created via
 
`rtiddsgen -language C++11 -platform x64Linux4gcc7.3.0 -example x64Linux4gcc7.3.0 -create makefiles -create typefiles -d c++11 shapes.idl`

This example attempts to demonstrate the Listener hierarchy, which is done by overriding each level of templated listener inside participant_listener.hpp, and assigning it after casting to the publisher's domain participant and the subscriber's domain participant. Each override writes out the hex address of the class, class name (DataReaderListener, DataWriterListener etc) followed by the name of the overridden function.

DataReader - PublisherListener  \
             TopicListener       -- DomainParticipantListener
DataWriter - SubscriberListener /