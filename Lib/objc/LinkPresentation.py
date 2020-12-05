"""
Classes from the 'LinkPresentation' framework.
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


LPMultipleMetadataPresentationTransformer = _Class(
    "LPMultipleMetadataPresentationTransformer"
)
LPLinkHTMLTextGenerator = _Class("LPLinkHTMLTextGenerator")
LPLinkMetadataStoreTransformer = _Class("LPLinkMetadataStoreTransformer")
LPTestingOverrides = _Class("LPTestingOverrides")
LPResources = _Class("LPResources")
LPAnimatedImageTranscoder = _Class("LPAnimatedImageTranscoder")
LPLinkMetadataObserver = _Class("LPLinkMetadataObserver")
LPPresentationSpecializations = _Class("LPPresentationSpecializations")
LPYouTubeURLComponents = _Class("LPYouTubeURLComponents")
LPStatistics = _Class("LPStatistics")
LPLinkMetadataPresentationTransformer = _Class("LPLinkMetadataPresentationTransformer")
LPYouTubePlayerScriptMessageHandler = _Class("LPYouTubePlayerScriptMessageHandler")
LPiTunesMediaURLComponents = _Class("LPiTunesMediaURLComponents")
LPAudio = _Class("LPAudio")
LPAudioProperties = _Class("LPAudioProperties")
LPLinkViewComponents = _Class("LPLinkViewComponents")
LPMessagesPayload = _Class("LPMessagesPayload")
RichLinkAttachmentSubstituter = _Class("RichLinkAttachmentSubstituter")
LPTheme = _Class("LPTheme")
LPThemeParametersObserver = _Class("LPThemeParametersObserver")
LPTapToLoadViewStyle = _Class("LPTapToLoadViewStyle")
LPCaptionBarStyle = _Class("LPCaptionBarStyle")
LPMusicPlayButtonStyle = _Class("LPMusicPlayButtonStyle")
LPVideoViewStyle = _Class("LPVideoViewStyle")
LPVideoPlayButtonStyle = _Class("LPVideoPlayButtonStyle")
LPGlyphStyle = _Class("LPGlyphStyle")
LPImageViewStyle = _Class("LPImageViewStyle")
LPButtonStyle = _Class("LPButtonStyle")
LPShadowStyle = _Class("LPShadowStyle")
LPCaptionBarAccessoryStyle = _Class("LPCaptionBarAccessoryStyle")
LPVerticalTextStackViewStyle = _Class("LPVerticalTextStackViewStyle")
LPTextRowStyle = _Class("LPTextRowStyle")
LPTextViewStyle = _Class("LPTextViewStyle")
LPPadding = _Class("LPPadding")
LPSize = _Class("LPSize")
LPPointUnit = _Class("LPPointUnit")
LPStreamingAudioPlayer = _Class("LPStreamingAudioPlayer")
LPVideo = _Class("LPVideo")
LPVideoAttachmentSubstitute = _Class("LPVideoAttachmentSubstitute")
LPVideoProperties = _Class("LPVideoProperties")
LPEventTimeline = _Class("LPEventTimeline")
LPEvent = _Class("LPEvent")
LPiTunesMediaStorefrontMappings = _Class("LPiTunesMediaStorefrontMappings")
LPAppLinkPresentationProperties = _Class("LPAppLinkPresentationProperties")
LPMetadataProviderSpecializationContext = _Class(
    "LPMetadataProviderSpecializationContext"
)
LPWebLinkPresentationProperties = _Class("LPWebLinkPresentationProperties")
LPCardHeadingPresentationProperties = _Class("LPCardHeadingPresentationProperties")
LPFullScreenVideoController = _Class("LPFullScreenVideoController")
LPMetadataProvider = _Class("LPMetadataProvider")
LPMIMETypeRegistry = _Class("LPMIMETypeRegistry")
LPiTunesMediaMovieBundleUnresolvedMetadata = _Class(
    "LPiTunesMediaMovieBundleUnresolvedMetadata"
)
LPiTunesMediaMovieUnresolvedMetadata = _Class("LPiTunesMediaMovieUnresolvedMetadata")
LPiTunesMediaTVShowUnresolvedMetadata = _Class("LPiTunesMediaTVShowUnresolvedMetadata")
LPiTunesMediaTVSeasonUnresolvedMetadata = _Class(
    "LPiTunesMediaTVSeasonUnresolvedMetadata"
)
LPiTunesMediaTVEpisodeUnresolvedMetadata = _Class(
    "LPiTunesMediaTVEpisodeUnresolvedMetadata"
)
LPiTunesMediaPodcastUnresolvedMetadata = _Class(
    "LPiTunesMediaPodcastUnresolvedMetadata"
)
LPiTunesMediaPodcastEpisodeUnresolvedMetadata = _Class(
    "LPiTunesMediaPodcastEpisodeUnresolvedMetadata"
)
LPiTunesMediaAudioBookUnresolvedMetadata = _Class(
    "LPiTunesMediaAudioBookUnresolvedMetadata"
)
LPiTunesMediaBookUnresolvedMetadata = _Class("LPiTunesMediaBookUnresolvedMetadata")
LPiTunesMediaSoftwareUnresolvedMetadata = _Class(
    "LPiTunesMediaSoftwareUnresolvedMetadata"
)
LPiTunesMediaRadioUnresolvedMetadata = _Class("LPiTunesMediaRadioUnresolvedMetadata")
LPiTunesMediaPlaylistUnresolvedMetadata = _Class(
    "LPiTunesMediaPlaylistUnresolvedMetadata"
)
LPiTunesMediaArtistUnresolvedMetadata = _Class("LPiTunesMediaArtistUnresolvedMetadata")
LPiTunesMediaMusicVideoUnresolvedMetadata = _Class(
    "LPiTunesMediaMusicVideoUnresolvedMetadata"
)
LPiTunesMediaAlbumUnresolvedMetadata = _Class("LPiTunesMediaAlbumUnresolvedMetadata")
LPiTunesMediaSongUnresolvedMetadata = _Class("LPiTunesMediaSongUnresolvedMetadata")
LPiTunesMediaAsset = _Class("LPiTunesMediaAsset")
LPMediaPlaybackManager = _Class("LPMediaPlaybackManager")
LPiTunesMediaOffer = _Class("LPiTunesMediaOffer")
LPiTunesMediaLookupItemArtwork = _Class("LPiTunesMediaLookupItemArtwork")
LPiTunesStoreInformation = _Class("LPiTunesStoreInformation")
LPSettings = _Class("LPSettings")
LPSharingMetadataWrapper = _Class("LPSharingMetadataWrapper")
LPImagePresentationProperties = _Class("LPImagePresentationProperties")
LPCaptionBarPresentationProperties = _Class("LPCaptionBarPresentationProperties")
LPCaptionRowPresentationProperties = _Class("LPCaptionRowPresentationProperties")
LPCaptionPresentationProperties = _Class("LPCaptionPresentationProperties")
LPCaptionButtonPresentationProperties = _Class("LPCaptionButtonPresentationProperties")
LPVideoViewConfiguration = _Class("LPVideoViewConfiguration")
LPApplicationCompatibilityQuirks = _Class("LPApplicationCompatibilityQuirks")
LPURLSuffixChecker = _Class("LPURLSuffixChecker")
LPFetcherGroup = _Class("LPFetcherGroup")
LPFetcherGroupTask = _Class("LPFetcherGroupTask")
LPFetcherConfiguration = _Class("LPFetcherConfiguration")
LPLinkMetadataStatusTransformer = _Class("LPLinkMetadataStatusTransformer")
LPAssociatedApplicationMetadata = _Class("LPAssociatedApplicationMetadata")
LPSpecializationMetadata = _Class("LPSpecializationMetadata")
LPSummarizedLinkMetadata = _Class("LPSummarizedLinkMetadata")
LPAppStoreStoryMetadata = _Class("LPAppStoreStoryMetadata")
LPWalletPassMetadata = _Class("LPWalletPassMetadata")
LPBusinessChatMetadata = _Class("LPBusinessChatMetadata")
LPSharingStatusMetadata = _Class("LPSharingStatusMetadata")
LPApplePhotosStatusMetadata = _Class("LPApplePhotosStatusMetadata")
LPApplePhotosMomentMetadata = _Class("LPApplePhotosMomentMetadata")
LPAppleTVMetadata = _Class("LPAppleTVMetadata")
LPAppleNewsMetadata = _Class("LPAppleNewsMetadata")
LPFileMetadata = _Class("LPFileMetadata")
LPMapCollectionPublisherMetadata = _Class("LPMapCollectionPublisherMetadata")
LPMapCollectionMetadata = _Class("LPMapCollectionMetadata")
LPMapMetadata = _Class("LPMapMetadata")
LPiCloudFamilyInvitationMetadata = _Class("LPiCloudFamilyInvitationMetadata")
LPGameCenterInvitationMetadata = _Class("LPGameCenterInvitationMetadata")
LPiCloudSharingMetadata = _Class("LPiCloudSharingMetadata")
LPiTunesMediaMovieBundleMetadata = _Class("LPiTunesMediaMovieBundleMetadata")
LPiTunesMediaMovieMetadata = _Class("LPiTunesMediaMovieMetadata")
LPAppleMusicTVShowMetadata = _Class("LPAppleMusicTVShowMetadata")
LPiTunesMediaTVSeasonMetadata = _Class("LPiTunesMediaTVSeasonMetadata")
LPiTunesMediaTVEpisodeMetadata = _Class("LPiTunesMediaTVEpisodeMetadata")
LPiTunesMediaPodcastMetadata = _Class("LPiTunesMediaPodcastMetadata")
LPiTunesMediaPodcastEpisodeMetadata = _Class("LPiTunesMediaPodcastEpisodeMetadata")
LPiTunesMediaAudioBookMetadata = _Class("LPiTunesMediaAudioBookMetadata")
LPiTunesMediaBookMetadata = _Class("LPiTunesMediaBookMetadata")
LPiTunesMediaSoftwareMetadata = _Class("LPiTunesMediaSoftwareMetadata")
LPiTunesMediaRadioMetadata = _Class("LPiTunesMediaRadioMetadata")
LPiTunesMediaPlaylistMetadata = _Class("LPiTunesMediaPlaylistMetadata")
LPiTunesUserProfileMetadata = _Class("LPiTunesUserProfileMetadata")
LPiTunesMediaArtistMetadata = _Class("LPiTunesMediaArtistMetadata")
LPiTunesMediaMusicVideoMetadata = _Class("LPiTunesMediaMusicVideoMetadata")
LPiTunesMediaAlbumMetadata = _Class("LPiTunesMediaAlbumMetadata")
LPiTunesMediaSongMetadata = _Class("LPiTunesMediaSongMetadata")
LPAudioMetadata = _Class("LPAudioMetadata")
LPVideoMetadata = _Class("LPVideoMetadata")
LPArtworkMetadata = _Class("LPArtworkMetadata")
LPImageMetadata = _Class("LPImageMetadata")
LPIconMetadata = _Class("LPIconMetadata")
LPLinkMetadata = _Class("LPLinkMetadata")
LPPlaceholderLinkMetadata = _Class("LPPlaceholderLinkMetadata")
LPLinkHTMLGenerator = _Class("LPLinkHTMLGenerator")
LPApplicationIdentification = _Class("LPApplicationIdentification")
LPImageRemoteURLRepresentation = _Class("LPImageRemoteURLRepresentation")
LPImage = _Class("LPImage")
LPImageAttachmentSubstitute = _Class("LPImageAttachmentSubstitute")
LPImageProperties = _Class("LPImageProperties")
LPMetadataProviderSpecialization = _Class("LPMetadataProviderSpecialization")
LPAppleMapsMetadataProviderSpecialization = _Class(
    "LPAppleMapsMetadataProviderSpecialization"
)
LPFileMetadataProviderSpecialization = _Class("LPFileMetadataProviderSpecialization")
LPiCloudSharingMetadataProviderSpecialization = _Class(
    "LPiCloudSharingMetadataProviderSpecialization"
)
LPAppStoreStoryMetadataProviderSpecialization = _Class(
    "LPAppStoreStoryMetadataProviderSpecialization"
)
LPAppleTVMetadataProviderSpecialization = _Class(
    "LPAppleTVMetadataProviderSpecialization"
)
LPApplePhotosMetadataProviderSpecialization = _Class(
    "LPApplePhotosMetadataProviderSpecialization"
)
LPiTunesMediaMetadataProviderSpecialization = _Class(
    "LPiTunesMediaMetadataProviderSpecialization"
)
LPAppleNewsMetadataProviderSpecialization = _Class(
    "LPAppleNewsMetadataProviderSpecialization"
)
LPRedditMetadataProviderSpecialization = _Class(
    "LPRedditMetadataProviderSpecialization"
)
LPStreamingMediaMetadataProviderSpecialization = _Class(
    "LPStreamingMediaMetadataProviderSpecialization"
)
LPInlineMediaPlaybackInformation = _Class("LPInlineMediaPlaybackInformation")
LPLinkMetadataPreviewTransformer = _Class("LPLinkMetadataPreviewTransformer")
LPFetcherResponse = _Class("LPFetcherResponse")
LPFetcherClipMetadataResponse = _Class("LPFetcherClipMetadataResponse")
LPFetcherErrorResponse = _Class("LPFetcherErrorResponse")
LPFetcherURLResponse = _Class("LPFetcherURLResponse")
LPFetcherStringResponse = _Class("LPFetcherStringResponse")
LPFetcherJSONResponse = _Class("LPFetcherJSONResponse")
LPFetcherImageResponse = _Class("LPFetcherImageResponse")
LPFetcherAccessibilityEnabledImageResponse = _Class(
    "LPFetcherAccessibilityEnabledImageResponse"
)
LPFetcherAudioResponse = _Class("LPFetcherAudioResponse")
LPFetcherAccessibilityEnabledAudioResponse = _Class(
    "LPFetcherAccessibilityEnabledAudioResponse"
)
LPFetcherVideoResponse = _Class("LPFetcherVideoResponse")
LPFetcherAccessibilityEnabledVideoResponse = _Class(
    "LPFetcherAccessibilityEnabledVideoResponse"
)
LPFetcher = _Class("LPFetcher")
LPAssociatedApplicationMetadataFetcher = _Class(
    "LPAssociatedApplicationMetadataFetcher"
)
LPURLFetcher = _Class("LPURLFetcher")
LPMediaAssetFetcher = _Class("LPMediaAssetFetcher")
LPCSSResolver = _Class("LPCSSResolver")
LPCSSVariable = _Class("LPCSSVariable")
LPHTMLComponent = _Class("LPHTMLComponent")
LPEmailCompatibleHTMLCaptionBarRowComponent = _Class(
    "LPEmailCompatibleHTMLCaptionBarRowComponent"
)
LPHTMLTextComponent = _Class("LPHTMLTextComponent")
LPEmailCompatibleHTMLVerticalTextStackComponent = _Class(
    "LPEmailCompatibleHTMLVerticalTextStackComponent"
)
LPEmailCompatibleHTMLQuoteComponent = _Class("LPEmailCompatibleHTMLQuoteComponent")
LPHTMLImageComponent = _Class("LPHTMLImageComponent")
LPHTMLTapToLoadComponent = _Class("LPHTMLTapToLoadComponent")
LPEmailCompatibleHTMLCaptionBarItemComponent = _Class(
    "LPEmailCompatibleHTMLCaptionBarItemComponent"
)
LPEmailCompatibleHTMLTextComponent = _Class("LPEmailCompatibleHTMLTextComponent")
LPEmailCompatibleHTMLLinkComponent = _Class("LPEmailCompatibleHTMLLinkComponent")
LPHTMLVideoComponent = _Class("LPHTMLVideoComponent")
LPHTMLLinkComponent = _Class("LPHTMLLinkComponent")
LPHTMLImageContainerComponent = _Class("LPHTMLImageContainerComponent")
LPEmailCompatibleHTMLTableComponent = _Class("LPEmailCompatibleHTMLTableComponent")
LPHTMLCaptionBarAccessoryComponent = _Class("LPHTMLCaptionBarAccessoryComponent")
LPHTMLMultipleImageComponent = _Class("LPHTMLMultipleImageComponent")
LPHTMLIconComponent = _Class("LPHTMLIconComponent")
LPHTMLHorizontalCaptionPairComponent = _Class("LPHTMLHorizontalCaptionPairComponent")
LPHTMLCaptionBarComponent = _Class("LPHTMLCaptionBarComponent")
LPHTMLGlyphComponent = _Class("LPHTMLGlyphComponent")
LPEmailCompatibleHTMLInnerLinkComponent = _Class(
    "LPEmailCompatibleHTMLInnerLinkComponent"
)
LPHTMLVerticalTextStackComponent = _Class("LPHTMLVerticalTextStackComponent")
LPEmailCompatibleHTMLImageComponent = _Class("LPEmailCompatibleHTMLImageComponent")
LPEmailCompatibleHTMLIconComponent = _Class("LPEmailCompatibleHTMLIconComponent")
LPHTMLQuoteComponent = _Class("LPHTMLQuoteComponent")
LPEmailCompatibleHTMLCaptionBarComponent = _Class(
    "LPEmailCompatibleHTMLCaptionBarComponent"
)
LPActionDisablingCALayerDelegate = _Class("LPActionDisablingCALayerDelegate")
LPiTunesMediaLookupTask = _Class("LPiTunesMediaLookupTask")
LPHighlightGestureRecognizer = _Class("LPHighlightGestureRecognizer")
LPYouTubePlayerView = _Class("LPYouTubePlayerView")
LPLinkView = _Class("LPLinkView")
LPPlayButtonShapeView = _Class("LPPlayButtonShapeView")
LPAnimationMaskView = _Class("LPAnimationMaskView")
LPFlippedView = _Class("LPFlippedView")
LPComponentView = _Class("LPComponentView")
LPTapToLoadView = _Class("LPTapToLoadView")
LPCaptionBarButtonView = _Class("LPCaptionBarButtonView")
LPDomainNameIndicator = _Class("LPDomainNameIndicator")
LPCaptionBarView = _Class("LPCaptionBarView")
LPPlayButtonView = _Class("LPPlayButtonView")
LPCaptionBarAccessoryView = _Class("LPCaptionBarAccessoryView")
LPTextView = _Class("LPTextView")
LPImageView = _Class("LPImageView")
LPImageStackView = _Class("LPImageStackView")
LPVerticalTextStackView = _Class("LPVerticalTextStackView")
LPIndeterminateProgressSpinnerView = _Class("LPIndeterminateProgressSpinnerView")
LPMultipleImageView = _Class("LPMultipleImageView")
LPHorizontalCaptionPairView = _Class("LPHorizontalCaptionPairView")
LPVideoView = _Class("LPVideoView")
LPYouTubeVideoView = _Class("LPYouTubeVideoView")
LPStreamingVideoView = _Class("LPStreamingVideoView")
LPPlayButtonControl = _Class("LPPlayButtonControl")
LPPlaceholderPlayButtonControl = _Class("LPPlaceholderPlayButtonControl")
LPStreamingAudioPlayButtonControl = _Class("LPStreamingAudioPlayButtonControl")
LPiTunesPlayButtonControl = _Class("LPiTunesPlayButtonControl")
LPAVPlayerViewController = _Class("LPAVPlayerViewController")
