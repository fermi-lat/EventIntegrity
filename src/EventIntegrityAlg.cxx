/** 
* @file EventIntegrityAlg.cxx
* @brief Declaration and definition of the algorithm EventIntegrityAlg.
*
*  $Header: /nfs/slac/g/glast/ground/cvs/EventIntegrity/src/EventIntegrityAlg.cxx,v 1.13.184.1 2012/01/26 04:47:27 heather Exp $
*/

#include "GaudiKernel/MsgStream.h"
#include "GaudiKernel/AlgFactory.h"
#include "GaudiKernel/IDataProviderSvc.h"
#include "GaudiKernel/SmartDataPtr.h"
#include "GaudiKernel/Algorithm.h"
#include "GaudiKernel/Property.h"

#include "GaudiKernel/SmartDataPtr.h"
#include "GaudiKernel/StatusCode.h"

#include "Event/TopLevel/EventModel.h"
#include "Event/TopLevel/Event.h"

#include "LdfEvent/EventSummaryData.h"

/*! \class EventIntegrityAlg
\brief  alg that sets trigger information

@section Attributes for job options:
@param run [0] For setting the run number
@param mask [-1] mask to apply to error flag. -1 means any, 0 means all.

*/

class EventIntegrityAlg : public Algorithm {

public:

    //! Constructor of this form must be provided
    EventIntegrityAlg(const std::string& name, ISvcLocator* pSvcLocator); 

    StatusCode initialize();
    StatusCode execute();
    StatusCode finalize();

private:

    unsigned int m_mask;

};

//static const AlgFactory<EventIntegrityAlg>  Factory;
//const IAlgFactory& EventIntegrityAlgFactory = Factory;
DECLARE_ALGORITHM_FACTORY(EventIntegrityAlg);


EventIntegrityAlg::EventIntegrityAlg(const std::string& name, ISvcLocator* pSvcLocator) :
Algorithm(name, pSvcLocator)
{
    declareProperty("mask"     ,  m_mask=0x0022003d); // event flag mask

}

namespace {
    int skipCount;
}

StatusCode EventIntegrityAlg::initialize() 
{
    StatusCode sc = StatusCode::SUCCESS;

    MsgStream log(msgSvc(), name());

    // Use the Job options service to set the Algorithm's parameters
    setProperties();

    log << MSG::INFO;
    if(log.isActive()) { 
        log.stream() <<"Applying event flag mask: " 
                     <<  std::setbase(16) <<m_mask;
    }
    log << endreq;

    skipCount = 0;

    return sc;
}

StatusCode EventIntegrityAlg::execute() 
{

    // Purpose and Method: Check the event flag bits and filter events as 
    //                     requested 

    StatusCode  sc = StatusCode::SUCCESS;
    MsgStream   log( msgSvc(), name() );

   // Retrieve the Event data for this event
 SmartDataPtr<Event::EventHeader> evtTds(eventSvc(), EventModel::EventHeader);
 if (!evtTds) {
    log << MSG::DEBUG << "No Event Header Found" << endreq;
    return sc;
 }

 SmartDataPtr<LdfEvent::EventSummaryData> summary(eventSvc(), "/Event/EventSummary");
    if( summary==0 ) {
        log << MSG::DEBUG << "No EventSummary found" << endreq;
        // if no EventSummary is available (and hence no event flag)
        // just accept the event - this might be a simulated event.. 
        // regardless we should carry on
        return sc;
     }

    unsigned int flags = summary->eventFlags();

    // If the Event Flags do exist on the TDS - check them
    // dump the event if any bit in the mask is set
    std::string errorMessage = "";
    if( (m_mask!=0) && ( flags & m_mask) ) { 
        // Ignoring TkrRecon Error bit
        if ( summary->badLdfStatus()) {
            errorMessage += " Bad LDF Status;";
         }
        if (summary->packetError()) {
            errorMessage += " Packet Error;";
        }
        if ( summary->temError() ) {
            errorMessage += " TEM Error;";
        }
        if (summary->badEventSeq()) {
            errorMessage += " Bad Event Seq;";
         }
        if (summary->trgParityError()) {
            errorMessage += " Trig. Parity Error;";
        }
        if (summary->temBug()) {
            errorMessage += " TEM bug;";        
        }
        if (summary->phaseError()) {
           errorMessage += " Phase Error;";
        }
        if (errorMessage!="") {
            setFilterPassed(false);
            log << MSG::INFO << "Event " << evtTds->event() << " skipped - flag 0x" << std::hex << flags
                << ":" << errorMessage << endreq;
            skipCount++;
        }
        if (summary->gtrcPhase()) {
           setFilterPassed(false);
            log << MSG::INFO << "Event Flag 0x" << std::hex << flags
                << " GTRC Phase Error set - skipping "
                << std::dec << evtTds->event() << endreq;
        }
        if (summary->gtfePhase()) {
           setFilterPassed(false);
            log << MSG::INFO << "Event Flag 0x" << std::hex << flags
                << " GTFE Phase Error set - skipping "
                << std::dec << evtTds->event() << endreq;
        }
        if (summary->gtccFifo()) {
           setFilterPassed(false);
            log << MSG::INFO << "Event Flag 0x" << std::hex << flags
                << " GTCC FIFO Error set - skipping "
                << std::dec << evtTds->event() << endreq;
        }
        if (summary->gtccHdrParity()) {
           setFilterPassed(false);
            log << MSG::INFO << "Event Flag 0x" << std::hex << flags
                << " GTCC HdrParity set - skipping "
                << std::dec << evtTds->event() << endreq;
        }
        if (summary->gtccWcParity()) {
           setFilterPassed(false);
            log << MSG::INFO << "Event Flag 0x" << std::hex << flags
                << " GTCC WcParity set - skipping "
                << std::dec << evtTds->event() << endreq;
        }
        if (summary->gtrcSummary()) {
           setFilterPassed(false);
            log << MSG::INFO << "Event Flag 0x" << std::hex << flags
                << " GTRC Summary set - skipping "
                << std::dec << evtTds->event() << endreq;
        }
        if (summary->gtccDataParity()) {
           setFilterPassed(false);
            log << MSG::INFO << "Event Flag 0x" << std::hex << flags
                << " GTCC Data Parity set - skipping "
                << std::dec << evtTds->event() << endreq;
        }
        if (summary->gtccTimeout()) {
           setFilterPassed(false);
            log << MSG::INFO << "Event Flag 0x" << std::hex << flags
                << " GTCC Timeout set - skipping "
                << std::dec << evtTds->event() << endreq;
        }
        if (summary->gcccError()) {
           setFilterPassed(false);
            log << MSG::INFO << "Event Flag 0x" << std::hex << flags
                << " GCCC Error set - skipping "
                << std::dec << evtTds->event() << endreq;
        }
        if (summary->gtccError()) {
           setFilterPassed(false);
            log << MSG::INFO << "Event Flag 0x" << std::hex << flags
                << " GTCC Error set - skipping "
                << std::dec << evtTds->event() << endreq;
        }
        if (summary->timeoutError()) {
           setFilterPassed(false);
            log << MSG::INFO << "Event Flag 0x" << std::hex << flags
                << " Timeout Error set - skipping "
                << std::dec << evtTds->event() << endreq;
        }
      
    } 

    return sc;
}

StatusCode EventIntegrityAlg::finalize() {

    //setFinalized(); No longer available in Gaudi v21r7
    StatusCode  sc = StatusCode::SUCCESS;

    MsgStream log(msgSvc(), name());
    log << MSG::INFO << skipCount << " event(s) skipped" << endreq;

    return StatusCode::SUCCESS;
}

