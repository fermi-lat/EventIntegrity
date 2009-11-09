# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/EventIntegrity/EventIntegrityLib.py,v 1.2 2008/08/28 21:50:54 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['EventIntegrity'])
    env.Tool('GlastSvcLib')
    env.Tool('LdfEventLib')
def exists(env):
    return 1;
