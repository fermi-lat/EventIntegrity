# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/EventIntegrity/SConscript,v 1.10 2009/11/10 01:23:38 jrb Exp $
# Authors: H. Kelly <heather@milkyway.gsfc.nasa.gov>
# Version: EventIntegrity-00-08-03-gr01
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('EventIntegrityLib', depsOnly = 1)
EventIntegrity = libEnv.SharedLibrary('EventIntegrity', listFiles(['src/*.cxx','src/Dll/*.cxx']))


progEnv.Tool('EventIntegrityLib')
test_EventIntegrity = progEnv.GaudiProgram('test_EventIntegrity', listFiles(['src/test/*.cxx']), test = 1)

progEnv.Tool('registerTargets', package = 'EventIntegrity',
             libraryCxts = [[EventIntegrity,libEnv]],
             testAppCxts = [[test_EventIntegrity, progEnv]],
             includes = listFiles(['EventIntegrity/*.h']))
