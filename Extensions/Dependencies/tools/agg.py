

# Code implemented by Pyto for showing images with the AGG backend

def _show(block=None):
    from matplotlib._pylab_helpers import Gcf
    active_manager = Gcf.get_active()
    
    if active_manager:
        import _sharing as sharing
        import tempfile, os
        filepath = os.path.join(tempfile.gettempdir(), 'figure.png')
                
        remove_previous = (block == False)
        
        i = 1
        while os.path.isfile(filepath):
            i += 1
            filepath = os.path.join(tempfile.gettempdir(), 'figure '+str(i)+'.png')
        
        active_manager.canvas.figure.savefig(filepath)
        sharing.quick_look(filepath, remove_previous)

show = _show
