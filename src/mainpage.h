//$Header: /nfs/slac/g/glast/ground/cvs/Trigger/src/mainpage.h,v 1.5 2004/08/11 20:57:41 burnett Exp $
// (Special "header" just for doxygen)

/*! @mainpage  package EventIntegrity 

Implements 
- EventIntegrityAlg 

\section s1 EventIntegrityAlg properties

@param mask [0xffffffff]  Mask to apply to the event flag to decide if event is accepted; if 0, accept all; default reject any set bit
    
\section s2 EventFlagWord bit definitions
    @verbatim
b_EVTSEQ =     1,  ///  Set if event sequence is not consistent or not
                  /// monotonically increasing 
    @endverbatim

  <hr>
  \section requirements requirements
  \include requirements
*/

