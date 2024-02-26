#pragma once
#include <iostream>

#include "dds/domain/DomainParticipantListener.hpp"
#include "dds/topic/TopicListener.hpp"
#include "dds/sub/DataReaderListener.hpp"
#include "dds/pub/DataWriterListener.hpp"

template <typename T>
class DataReaderListenerX : public dds::sub::DataReaderListener<T> {
    
    virtual void on_requested_deadline_missed(dds::sub::DataReader<T> &reader,
        const dds::core::status::RequestedDeadlineMissedStatus &status) { 

        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataReaderListener: on_requested_deadline_missed" << std::endl;
    }

    virtual void on_requested_incompatible_qos(dds::sub::DataReader<T> & reader,
        const dds::core::status::RequestedIncompatibleQosStatus &status) {

        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataReaderListener: on_requested_incompatible_qos" << std::endl;
    }

    virtual void on_sample_rejected(dds::sub::DataReader<T> &reader,
        const dds::core::status::SampleRejectedStatus &status) {

        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataReaderListener: on_sample_rejected" << std::endl;
    }

    virtual void on_liveliness_changed(dds::sub::DataReader<T> &reader,
        const dds::core::status::LivelinessChangedStatus &status) {

        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataReaderListener: on_liveliness_changed" << std::endl;
    }

    virtual void on_data_available(dds::sub::DataReader<T> &reader) {

        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataReaderListener: on_data_available" << std::endl;
    }

    virtual void on_subscription_matched(dds::sub::DataReader<T> &reader,
        const dds::core::status::SubscriptionMatchedStatus &status) {

        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataReaderListener: on_subscription_matched" << std::endl;
    }

    virtual void on_sample_lost(dds::sub::DataReader<T> &reader,
        const dds::core::status::SampleLostStatus &status) {
        
        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataReaderListener: on_sample_lost" << std::endl;
    }
};

template <typename T>
class DataWriterListenerX : public dds::pub::NoOpDataWriterListener<T> {

    virtual void on_offered_deadline_missed(dds::pub::DataWriter<T>& writer, 
        const dds::core::status::OfferedDeadlineMissedStatus& status) {
        
        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataWriterListener: on_offered_deadline_missed" << std::endl;
    }

    virtual void on_offered_incompatible_qos(dds::pub::DataWriter<T> &writer,
        const dds::core::status::OfferedIncompatibleQosStatus &status) {

        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataWriterListener: on_offered_incompatible_qos" <<  std::endl;
    }

    virtual void on_liveliness_lost(dds::pub::DataWriter<T>& writer, 
        const dds::core::status::LivelinessLostStatus& status) {
        
        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataWriterListener: on_liveliness_lost" << std::endl;
    }

    virtual void on_publication_matched(dds::pub::DataWriter<T>& writer, 
        const dds::core::status::PublicationMatchedStatus& status) {

        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataWriterListener: on_publication_matched" << std::endl;
    }

    virtual void on_reliable_writer_cache_changed(dds::pub::DataWriter<T>& writer, 
        const rti::core::status::ReliableWriterCacheChangedStatus& status) {

        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataWriterListener: on_reliable_writer_cache_changed" << std::endl;
    }

    virtual void on_instance_replaced(dds::pub::DataWriter<T>&, 
        const dds::core::InstanceHandle& handle) {
        
        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataWriterListener: on_instance_replaced" << std::endl;
    }

    virtual void on_reliable_reader_activity_changed(dds::pub::DataWriter<T>& writer, 
        const rti::core::status::ReliableReaderActivityChangedStatus&) {

        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataWriterListener: on_reliable_reader_activity_changed" << std::endl;
    }

    virtual void on_application_acknowledgment(dds::pub::DataWriter<T>&, 
        const rti::pub::AcknowledgmentInfo&) {

        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataWriterListener: on_application_acknowledgment" << std::endl;
    }

    virtual void on_service_request_accepted(dds::pub::DataWriter<T>&, 
        const rti::core::status::ServiceRequestAcceptedStatus&) {

        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataWriterListener: on_service_request_accepted" << std::endl;
    }

    virtual void on_destination_unreachable(dds::pub::DataWriter<T>&, 
        const dds::core::InstanceHandle&, const rti::core::Locator&) {

        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataWriterListener: on_destination_unreachable" << std::endl;
    }

    // virtual void* on_data_request(dds::pub::DataWriter<T>&, 
    //     const rti::core::Cookie&) {
        
    //     std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
    //         "DataWriterListener: on_data_request" << std::endl;
    // }

    // virtual void on_data_return(dds::pub::DataWriter<T>&, void*, const rti::core::Cookie&) {
    //     std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
    //         "DataWriterListener: on_data_return" << std::endl;
    // }

    virtual void on_sample_removed(dds::pub::DataWriter<T>&, const rti::core::Cookie&) {
        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "DataWriterListener: on_data_return" << std::endl;
    }
};

template <typename T>
class PublisherListenerX : public DataWriterListenerX<T> {

};

template <typename T>
class SubscriberListenerX : public DataReaderListenerX<T> {
    virtual void on_data_on_readers(dds::sub::Subscriber &sub) {
        // Notify DataReaders only calls on_data_available for
        // DataReaders with unread samples.
        sub.notify_datareaders();
        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
            "SubscriberListener: on_data_on_readers" << std::endl;
    }
};

template <typename T>
class TopicListenerX : public dds::topic::TopicListener<T>  {
     
    virtual void on_inconsistent_topic( dds::topic::Topic<T> &topic,
        const dds::core::status::InconsistentTopicStatus &status) {
        
        std::cout << std::hex << std::showbase << reinterpret_cast<std::uintptr_t>(this) << std::dec << ": "
             "TopicListener: on_inconsistent_topic" << std::endl;
    }
};

template <typename T>
class ParticipantListenerX : public PublisherListenerX<T>, SubscriberListenerX<T>, TopicListenerX<T> {
    // This is functionally identical to NoOpDomainParticipantListener.
    // All this demonstrates is the hierarchy of the Listeners
};