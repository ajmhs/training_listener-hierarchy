/*
* (c) Copyright, Real-Time Innovations, 2020.  All rights reserved.
* RTI grants Licensee a license to use, modify, compile, and create derivative
* works of the software solely for use with RTI Connext DDS. Licensee may
* redistribute copies of the software provided that all such copies are subject
* to this license. The software is provided "as is", with no warranty of any
* type, including any warranty for fitness for any purpose. RTI is under no
* obligation to maintain or support the software. RTI shall not be liable for
* any incidental or consequential damages arising out of the use or inability
* to use the software.
*/

#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>      // for sleep()
#include <rti/config/Logger.hpp>  // for logging
// alternatively, to include all the standard APIs:
//  <dds/dds.hpp>
// or to include both the standard APIs and extensions:
//  <rti/rti.hpp>
//
// For more information about the headers and namespaces, see:
//    https://community.rti.com/static/documentation/connext-dds/7.2.0/doc/api/connext_dds/api_cpp2/group__DDSNamespaceModule.html
// For information on how to use extensions, see:
//    https://community.rti.com/static/documentation/connext-dds/7.2.0/doc/api/connext_dds/api_cpp2/group__DDSCpp2Conventions.html

#include "application.hpp"  // for command line parsing and ctrl-c
#include "shapes.hpp"

#include "participant_listener.hpp"

template <typename T>
class DWListener : public dds::pub::NoOpDataWriterListener<T> {

    void on_offered_deadline_missed(dds::pub::DataWriter<T>& writer, 
        const dds::core::status::OfferedDeadlineMissedStatus& status) {

    }

    void on_offered_incompatible_qos(dds::pub::DataWriter<T>& writer, 
        const dds::core::status::OfferedIncompatibleQosStatus& status) {

    }

    void on_liveliness_lost(dds::pub::DataWriter<T>& writer, 
        const dds::core::status::LivelinessLostStatus& status) {

    }

    void on_publication_matched(dds::pub::DataWriter<T>& writer, 
        const dds::core::status::PublicationMatchedStatus& status) {

    }

    void on_reliable_writer_cache_changed(dds::pub::DataWriter<T>& writer, 
        const rti::core::status::ReliableWriterCacheChangedStatus& status) {

    }

    void on_reliable_reader_activity_changed(dds::pub::DataWriter<T>& writer,
        const rti::core::status::ReliableReaderActivityChangedStatus& status) {

    }

    void on_instance_replaced(dds::pub::DataWriter<T>& writer, 
        const dds::core::InstanceHandle& handle) {

    }

    void on_application_acknowledgment(dds::pub::DataWriter<T>& writer,
        const rti::pub::AcknowledgmentInfo& info) {

    }

    void on_service_request_accepted(dds::pub::DataWriter<T>& writer,
        const rti::core::status::ServiceRequestAcceptedStatus& status) {

    }
    
    void on_destination_unreachable(dds::pub::DataWriter<T>& writer, 
        const dds::core::InstanceHandle& handle, const rti::core::Locator& locator) {

    } 
    // Tried not to use the no-op version so I'm forced to override the pure virtual functions
    // But I can't see in the docs what's expected of these two functions:

    // void* on_data_request(dds::pub::DataWriter<T>& writer,
    //     const rti::core::Cookie& cookie) {

    // }

    // void on_data_return(dds::pub::DataWriter<T>& writer, 
    //     void*, 
    //     const rti::core::Cookie& cookie) {

    // }

    void on_sample_removed(dds::pub::DataWriter<T>& writer, 
        const rti::core::Cookie& cookie) {

    }
};


using ShapesDWListener = DWListener< ::ShapeTypeExtended>;

void run_publisher_application(unsigned int domain_id, unsigned int sample_count)
{
    // DDS objects behave like shared pointers or value types
    // (see https://community.rti.com/best-practices/use-modern-c-types-correctly)

    // Start communicating in a domain, usually one participant per application
    dds::domain::DomainParticipant participant(domain_id);
    
    // Create and assign a DomainParticipantListener to the participant, from the FrankenListener
    ParticipantListenerX<ShapeTypeExtended>* my_listener = new ParticipantListenerX<ShapeTypeExtended>;
    std::shared_ptr<dds::domain::DomainParticipantListener> participant_listener( (dds::domain::DomainParticipantListener*)my_listener);
    participant.set_listener(participant_listener);

    // Create a Topic with a name and a datatype
    dds::topic::Topic< ::ShapeTypeExtended> topic(participant, "Circle");
    
    // Create a Publisher
    dds::pub::Publisher publisher(participant);

    // Create a DataWriter with default QoS
    dds::pub::DataWriter< ::ShapeTypeExtended> writer(publisher, topic);
    
    ::ShapeTypeExtended data;
    // Main loop, write data
    for (unsigned int samples_written = 0;
    !application::shutdown_requested && samples_written < sample_count;
    samples_written++) {
        // Modify the data to be written here
        std::cout << "Writing ::ShapeTypeExtended, count " << samples_written << std::endl;

        writer.write(data);

        // Send once every second
        rti::util::sleep(dds::core::Duration(1));
    }
}

int main(int argc, char *argv[])
{

    using namespace application;

    // Parse arguments and handle control-C
    auto arguments = parse_arguments(argc, argv);
    if (arguments.parse_result == ParseReturn::exit) {
        return EXIT_SUCCESS;
    } else if (arguments.parse_result == ParseReturn::failure) {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();

    // Sets Connext verbosity to help debugging
    rti::config::Logger::instance().verbosity(arguments.verbosity);

    try {
        run_publisher_application(arguments.domain_id, arguments.sample_count);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in run_publisher_application(): " << ex.what()
        << std::endl;
        return EXIT_FAILURE;
    }

    // Releases the memory used by the participant factory.  Optional at
    // application exit
    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
