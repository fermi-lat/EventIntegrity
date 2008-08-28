# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/EventIntegrity/EventIntegrityLib.py,v 1.1 2008/08/15 21:42:34 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['EventIntegrity'])
    env.Tool('GlastSvcLib')
def exists(env):
    return 1;
