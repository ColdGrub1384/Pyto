//
//  ComplicationController.swift
//  Pyto Watch Extension
//
//  Created by Adrian Labbé on 04-02-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import ClockKit

/// A complication for launching Pyto.
class ComplicationController: NSObject, CLKComplicationDataSource {
    
    // MARK: - Timeline Configuration
    
    func getSupportedTimeTravelDirections(for complication: CLKComplication, withHandler handler: @escaping (CLKComplicationTimeTravelDirections) -> Void) {
        handler([.backward, .forward])
    }
    
    func getTimelineStartDate(for complication: CLKComplication, withHandler handler: @escaping (Date?) -> Void) {
        handler(Date())
    }
    
    func getTimelineEndDate(for complication: CLKComplication, withHandler handler: @escaping (Date?) -> Void) {
        handler(Date())
    }
    
    func getPrivacyBehavior(for complication: CLKComplication, withHandler handler: @escaping (CLKComplicationPrivacyBehavior) -> Void) {
        handler(.hideOnLockScreen)
    }
    
    // MARK: - Timeline Population
    
    func getCurrentTimelineEntry(for complication: CLKComplication, withHandler handler: @escaping (CLKComplicationTimelineEntry?) -> Void) {
        // Call the handler with the current timeline entry
        
        if complication.family == .circularSmall {

            let template = CLKComplicationTemplateCircularSmallRingImage()
            template.fillFraction = 1
            template.imageProvider = CLKImageProvider(onePieceImage: UIImage(named: "Complication/Circular")!)
            let timelineEntry = CLKComplicationTimelineEntry(date: Date(), complicationTemplate: template)
            handler(timelineEntry)

        } else if complication.family == .utilitarianSmall {

            let template = CLKComplicationTemplateUtilitarianSmallRingImage()
            template.fillFraction = 1
            template.imageProvider = CLKImageProvider(onePieceImage: UIImage(named: "Complication/Utilitarian")!)
            let timelineEntry = CLKComplicationTimelineEntry(date: Date(), complicationTemplate: template)
            handler(timelineEntry)

        } else if complication.family == .modularSmall {

            let template = CLKComplicationTemplateModularSmallRingImage()
            template.fillFraction = 1
            template.imageProvider = CLKImageProvider(onePieceImage: UIImage(named: "Complication/Modular")!)
            let timelineEntry = CLKComplicationTimelineEntry(date: Date(), complicationTemplate: template)
            handler(timelineEntry)
        } else if complication.family == .extraLarge {
                        
            let template = CLKComplicationTemplateExtraLargeRingImage()
            template.fillFraction = 1
            template.imageProvider = CLKImageProvider(onePieceImage: UIImage(named: "Complication/Extra Large")!)
            let timelineEntry = CLKComplicationTimelineEntry(date: Date(), complicationTemplate: template)
            handler(timelineEntry)
        } else if complication.family == .graphicCorner {
            
            let template = CLKComplicationTemplateGraphicCornerCircularImage()
            template.imageProvider = CLKFullColorImageProvider(fullColorImage: UIImage(named: "Complication/Graphic Corner")!)
            let timelineEntry = CLKComplicationTimelineEntry(date: Date(), complicationTemplate: template)
            handler(timelineEntry)
        }  else if complication.family == .graphicBezel {
            
            let template = CLKComplicationTemplateGraphicBezelCircularText()
            template.textProvider = CLKSimpleTextProvider(text: "Pyto")
            let timelineEntry = CLKComplicationTimelineEntry(date: Date(), complicationTemplate: template)
            handler(timelineEntry)
        } else if complication.family == .graphicCircular {
            let template = CLKComplicationTemplateGraphicCircularImage()
            template.imageProvider = CLKFullColorImageProvider(fullColorImage: UIImage(named: "Complication/Graphic Circular")!)
            let timelineEntry = CLKComplicationTimelineEntry(date: Date(), complicationTemplate: template)
            handler(timelineEntry)
        } else {
            handler(nil)
        }
    }
    
    func getTimelineEntries(for complication: CLKComplication, before date: Date, limit: Int, withHandler handler: @escaping ([CLKComplicationTimelineEntry]?) -> Void) {
        // Call the handler with the timeline entries prior to the given date
        handler(nil)
    }
    
    func getTimelineEntries(for complication: CLKComplication, after date: Date, limit: Int, withHandler handler: @escaping ([CLKComplicationTimelineEntry]?) -> Void) {
        // Call the handler with the timeline entries after to the given date
        handler(nil)
    }
    
    // MARK: - Placeholder Templates
    
    func getLocalizableSampleTemplate(for complication: CLKComplication, withHandler handler: @escaping (CLKComplicationTemplate?) -> Void) {
        // This method will be called once per supported complication, and the results will be cached
        
        if complication.family == .circularSmall {

            let template = CLKComplicationTemplateCircularSmallRingImage()
            template.fillFraction = 1
            template.imageProvider = CLKImageProvider(onePieceImage: UIImage(named: "Complication/Circular")!)
            handler(template)

        } else if complication.family == .utilitarianSmall {

            let template = CLKComplicationTemplateUtilitarianSmallRingImage()
            template.fillFraction = 1
            template.imageProvider = CLKImageProvider(onePieceImage: UIImage(named: "Complication/Utilitarian")!)
            handler(template)

        } else if complication.family == .modularSmall {

            let template = CLKComplicationTemplateModularSmallRingImage()
            template.fillFraction = 1
            template.imageProvider = CLKImageProvider(onePieceImage: UIImage(named: "Complication/Modular")!)
            handler(template)
        } else if complication.family == .extraLarge {
                        
            let template = CLKComplicationTemplateExtraLargeRingImage()
            template.fillFraction = 1
            template.imageProvider = CLKImageProvider(onePieceImage: UIImage(named: "Complication/Extra Large")!)
            handler(template)
        } else if complication.family == .graphicCorner {
            
            let template = CLKComplicationTemplateGraphicCornerCircularImage()
            template.imageProvider = CLKFullColorImageProvider(fullColorImage: UIImage(named: "Complication/Graphic Corner")!)
            handler(template)
        }  else if complication.family == .graphicBezel {
            
            let template = CLKComplicationTemplateGraphicBezelCircularText()
            template.circularTemplate = CLKComplicationTemplateGraphicCircular()
            template.textProvider = CLKSimpleTextProvider(text: "Pyto")
            handler(template)
        } else if complication.family == .graphicCircular {
            
            let template = CLKComplicationTemplateGraphicCircularImage()
            template.imageProvider = CLKFullColorImageProvider(fullColorImage: UIImage(named: "Complication/Graphic Circular")!)
            handler(template)
        } else {
            handler(nil)
        }
    }
    
}
