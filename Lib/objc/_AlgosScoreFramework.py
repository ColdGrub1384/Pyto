'''
Classes from the 'AlgosScoreFramework' framework.
'''

try:
    from rubicon.objc import ObjCClass
except ValueError:
    def ObjCClass(name):
        return None


def _Class(name):
    try:
        return ObjCClass(name)
    except NameError:
        return None

    
AlgosScoreCSVReader = _Class('AlgosScoreCSVReader')
AlgosStreamScore = _Class('AlgosStreamScore')
AlgosScoreDataCSV = _Class('AlgosScoreDataCSV')
AlgosScoreFaceTimeDataCSV = _Class('AlgosScoreFaceTimeDataCSV')
AlgosScoreStreamDataCSV = _Class('AlgosScoreStreamDataCSV')
AlgosScoreCombiner = _Class('AlgosScoreCombiner')
AlgosConnectionScore = _Class('AlgosConnectionScore')
