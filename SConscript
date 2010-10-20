# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/EventIntegrity/SConscript,v 1.12.2.1 2010/10/08 16:23:01 heather Exp $
# Authors: H. Kelly <heather@milkyway.gsfc.nasa.gov>
# Version: EventIntegrity-00-08-04-gr01

Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='EventIntegrity', toBuild='component')
EventIntegrity = libEnv.ComponentLibrary('EventIntegrity',
                                         listFiles(['src/*.cxx']))


progEnv.Tool('EventIntegrityLib')

test_EventIntegrity = progEnv.GaudiProgram('test_EventIntegrity',
                                           listFiles(['src/test/*.cxx']),
                                           test = 1, package='EventIntegrity')

progEnv.Tool('registerTargets', package = 'EventIntegrity',
             libraryCxts = [[EventIntegrity,libEnv]],
             testAppCxts = [[test_EventIntegrity, progEnv]],
             includes = listFiles(['EventIntegrity/*.h']),
             jo = ['src/test/jobOptions.txt'])
