"""
Classes from the 'CorePrediction' framework.
"""

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


CPMLEvalutionResult = _Class("CPMLEvalutionResult")
CPMLStorageManager = _Class("CPMLStorageManager")
CPMLNaiveBayesStorageManager = _Class("CPMLNaiveBayesStorageManager")
CPMLSchema = _Class("CPMLSchema")
CPMLModelEvaluate = _Class("CPMLModelEvaluate")
CPMLDB = _Class("CPMLDB")
CPMLModel = _Class("CPMLModel")
CPMLKMeansModel = _Class("CPMLKMeansModel")
CPMLTrainer = _Class("CPMLTrainer")
