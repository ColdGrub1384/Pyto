'''
Classes from the 'MailSupport' framework.
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

    
MSSiriIntelligenceSettings = _Class('MSSiriIntelligenceSettings')
MSSearchSessionController = _Class('MSSearchSessionController')
MSRadarURLBuilder = _Class('MSRadarURLBuilder')
MSRadarInteraction = _Class('MSRadarInteraction')
MSMessageLoadingAnalyticController = _Class('MSMessageLoadingAnalyticController')
MSMessageListItemSelection = _Class('MSMessageListItemSelection')
MSFileCompression = _Class('MSFileCompression')
MSFetchMetricsController = _Class('MSFetchMetricsController')
MSDiagnosticManager = _Class('MSDiagnosticManager')
MSCustomProtocolURLSchemeHandler = _Class('MSCustomProtocolURLSchemeHandler')
MSTriageAction = _Class('MSTriageAction')
MSMoveTriageAction = _Class('MSMoveTriageAction')
MSJunkTriageAction = _Class('MSJunkTriageAction')
MSDeleteTriageAction = _Class('MSDeleteTriageAction')
MSFlagChangeTriageAction = _Class('MSFlagChangeTriageAction')
MSReadTriageAction = _Class('MSReadTriageAction')
MSFlagTriageAction = _Class('MSFlagTriageAction')
MSConversationFlagChangeTriageAction = _Class('MSConversationFlagChangeTriageAction')
MSNotifyTriageAction = _Class('MSNotifyTriageAction')
MSMuteTriageAction = _Class('MSMuteTriageAction')
_MSCountableMatchesContext = _Class('_MSCountableMatchesContext')
MSComposeAttachmentAnalyticController = _Class('MSComposeAttachmentAnalyticController')
MSAttachmentInfo = _Class('MSAttachmentInfo')
MSAccountToEmailProvider = _Class('MSAccountToEmailProvider')
MSIntentMailResolutionResult = _Class('MSIntentMailResolutionResult')
MSIntentReadStatusResolutionResult = _Class('MSIntentReadStatusResolutionResult')
MSIntentMail = _Class('MSIntentMail')
MSSendMailIntentResponse = _Class('MSSendMailIntentResponse')
MSGetMailIntentResponse = _Class('MSGetMailIntentResponse')
MSSendMailIntent = _Class('MSSendMailIntent')
MSGetMailIntent = _Class('MSGetMailIntent')
AWDMailUserSuggestionsEngagment = _Class('AWDMailUserSuggestionsEngagment')
AWDMailUserEngagement = _Class('AWDMailUserEngagement')
AWDMailSearchSessionReport = _Class('AWDMailSearchSessionReport')
AWDMailSearchEngagement = _Class('AWDMailSearchEngagement')
AWDMailNetworkDiagnosticsReport = _Class('AWDMailNetworkDiagnosticsReport')
AWDMailMessageLoadingReport = _Class('AWDMailMessageLoadingReport')
AWDMailMessageDisplayErrorReport = _Class('AWDMailMessageDisplayErrorReport')
AWDMailMessageBody = _Class('AWDMailMessageBody')
AWDMailMessage = _Class('AWDMailMessage')
AWDMailFeatureEngagementReport = _Class('AWDMailFeatureEngagementReport')
AWDMailError = _Class('AWDMailError')
AWDMailComposeAttachmentReport = _Class('AWDMailComposeAttachmentReport')
AWDMailCannotGetMailErrorReport = _Class('AWDMailCannotGetMailErrorReport')
AWDMailAutoFetchReport = _Class('AWDMailAutoFetchReport')
MSSendMailIntentFormatter = _Class('MSSendMailIntentFormatter')
