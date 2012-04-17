# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/EventIntegrity/SConscript,v 1.13.48.1 2012/03/22 21:11:56 heather Exp $
# Authors: H. Kelly <heather@slac.stanford.edu>
# Version: EventIntegrity-00-08-05-gr03

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
