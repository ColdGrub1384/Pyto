'''
Classes from the 'HomeSharing' framework.
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

    
HSBook = _Class('HSBook')
HSCloudAvailabilityController = _Class('HSCloudAvailabilityController')
HSHomeSharingLibrary = _Class('HSHomeSharingLibrary')
HSConnection = _Class('HSConnection')
HSCloudClient = _Class('HSCloudClient')
HSWiFiManager = _Class('HSWiFiManager')
HSFairPlayInfo = _Class('HSFairPlayInfo')
HSBrowser = _Class('HSBrowser')
HSCloudItemIDList = _Class('HSCloudItemIDList')
HSAccountStore = _Class('HSAccountStore')
HSResponseDataParser = _Class('HSResponseDataParser')
HSConnectionConfiguration = _Class('HSConnectionConfiguration')
HSDAAPPropertyInfo = _Class('HSDAAPPropertyInfo')
HSResponse = _Class('HSResponse')
HSLoginResponse = _Class('HSLoginResponse')
HSUpdateResponse = _Class('HSUpdateResponse')
HSAuthorizedDSIDsUpdateResponse = _Class('HSAuthorizedDSIDsUpdateResponse')
HSContainersResponse = _Class('HSContainersResponse')
HSAuthorizedDSIDsUpdatesResponse = _Class('HSAuthorizedDSIDsUpdatesResponse')
HSBrowseResponse = _Class('HSBrowseResponse')
HSDatabasesResponse = _Class('HSDatabasesResponse')
HSGetAuthorizedAccountsTokenResponse = _Class('HSGetAuthorizedAccountsTokenResponse')
HSPlayStatusUpdateResponse = _Class('HSPlayStatusUpdateResponse')
HSNowPlayingArtworkResponse = _Class('HSNowPlayingArtworkResponse')
HSItemsResponse = _Class('HSItemsResponse')
HSRequest = _Class('HSRequest')
HSLoginRequest = _Class('HSLoginRequest')
HSUpdateRequest = _Class('HSUpdateRequest')
HSAuthorizedDSIDsUpdateRequest = _Class('HSAuthorizedDSIDsUpdateRequest')
HSPlaybackControlRequest = _Class('HSPlaybackControlRequest')
HSContainersRequest = _Class('HSContainersRequest')
HSAuthorizedDSIDsUpdatesRequest = _Class('HSAuthorizedDSIDsUpdatesRequest')
HSBrowseRequest = _Class('HSBrowseRequest')
HSCheckInRentalAssetRequest = _Class('HSCheckInRentalAssetRequest')
HSGetAuthorizedAccountsInfoRequest = _Class('HSGetAuthorizedAccountsInfoRequest')
HSDatabasesRequest = _Class('HSDatabasesRequest')
HSItemDataRequest = _Class('HSItemDataRequest')
HSGetAuthorizedAccountsTokenRequest = _Class('HSGetAuthorizedAccountsTokenRequest')
HSSetRentalPlaybackStartDateRequest = _Class('HSSetRentalPlaybackStartDateRequest')
HSServerInfoRequest = _Class('HSServerInfoRequest')
HSPlayStatusUpdateRequest = _Class('HSPlayStatusUpdateRequest')
HSFairPlaySetupRequest = _Class('HSFairPlaySetupRequest')
HSActivityRequest = _Class('HSActivityRequest')
HSNowPlayingArtworkRequest = _Class('HSNowPlayingArtworkRequest')
HSIncrementRequest = _Class('HSIncrementRequest')
HSLogoutRequest = _Class('HSLogoutRequest')
HSItemsRequest = _Class('HSItemsRequest')
HSHomeSharingVerifyRequest = _Class('HSHomeSharingVerifyRequest')
HSSetPropertyRequest = _Class('HSSetPropertyRequest')
HSArtworkRequest = _Class('HSArtworkRequest')
HSCheckOutRentalAssetRequest = _Class('HSCheckOutRentalAssetRequest')
