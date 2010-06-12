# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/EventIntegrity/SConscript,v 1.11 2010/06/11 00:35:08 jrb Exp $
# Authors: H. Kelly <heather@milkyway.gsfc.nasa.gov>
# Version: EventIntegrity-00-08-04
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='EventIntegrity', toBuild='component')
EventIntegrity = libEnv.SharedLibrary('EventIntegrity', listFiles(['src/*.cxx','src/Dll/*.cxx']))


progEnv.Tool('EventIntegrityLib')

test_EventIntegrity = progEnv.GaudiProgram('test_EventIntegrity',
                                           listFiles(['src/test/*.cxx']),
                                           test = 1, package='EventIntegrity')

progEnv.Tool('registerTargets', package = 'EventIntegrity',
             libraryCxts = [[EventIntegrity,libEnv]],
             testAppCxts = [[test_EventIntegrity, progEnv]],
             includes = listFiles(['EventIntegrity/*.h']),
             jo = ['src/test/jobOptions.txt'])
