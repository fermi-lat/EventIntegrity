# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/EventIntegrity/SConscript,v 1.6 2009/03/23 14:30:29 glastrm Exp $
# Authors: H. Kelly <heather@milkyway.gsfc.nasa.gov>
# Version: EventIntegrity-00-08-01
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('EventIntegrityLib', depsOnly = 1)
EventIntegrity = libEnv.SharedLibrary('EventIntegrity', listFiles(['src/*.cxx','src/Dll/*.cxx']))


progEnv.Tool('EventIntegrityLib')
test_EventIntegrity = progEnv.GaudiProgram('test_EventIntegrity', listFiles(['src/test/*.cxx']), test = 1)

progEnv.Tool('registerObjects', package = 'EventIntegrity', libraries = [EventIntegrity], testApps = [test_EventIntegrity], includes = listFiles(['EventIntegrity/*.h']))




