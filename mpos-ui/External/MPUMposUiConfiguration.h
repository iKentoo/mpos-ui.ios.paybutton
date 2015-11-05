/*
 * mpos-ui : http://www.payworksmobile.com
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 payworks GmbH
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#import <Foundation/Foundation.h>
#import <mpos.core/MPTransactionProvider.h>

@class MPUMposUiAppearance;

/**
 * Enum that describes the uses signature method.
 */
typedef NS_ENUM(NSUInteger, MPUMposUiConfigurationSignatureCapture) {
    /**
     * The signature is taken electronically. This is the default.
     */
    MPUMposUiConfigurationSignatureCaptureOnScreen = 0,
    
    /**
     * The signature is taken on paper after the transaction.
     */
    MPUMposUiConfigurationSignatureCaptureOnReceipt

};

/**
 * Options that describe the available features in the summary screen.
 */
typedef NS_OPTIONS(NSUInteger, MPUMposUiConfigurationSummaryFeature) {
    /** Option to disable all features */
    MPUMposUiConfigurationSummaryFeatureNone                    = 0,      // 00000000
    /** Option to enable sending receipt to customer via email. */
    MPUMposUiConfigurationSummaryFeatureSendReceiptViaEmail     = 1 << 0, // 00000001
    /** Option to enable printing receipt using a hardware printer. */
    MPUMposUiConfigurationSummaryFeaturePrintReceipt            = 1 << 1, // 00000010
    /** Option to enable refund transaction button right away. */
    MPUMposUiConfigurationSummaryFeatureRefundTransaction       = 1 << 2  // 00000100
};


/**
 * Class to specify the behavior of certain ViewControllers.
 */
@interface MPUMposUiConfiguration : NSObject

/**
 * The accessory family that will be used for the transaction.
 */
@property (nonatomic, assign) MPAccessoryFamily terminalFamily;

/**
 * The accessory family that will be used for the printer.
 */
@property (nonatomic, assign) MPAccessoryFamily printerFamily;

/**
 * The appearance that will be used for the transaction.
 */
@property (nonatomic, strong, nonnull) MPUMposUiAppearance *appearance;

/**
 * The signature method that will be used for the transaction.
 */
@property (nonatomic, assign) MPUMposUiConfigurationSignatureCapture signatureCapture;

/**
 * The features that will be enabled for the summary screen.
 */
@property (nonatomic, assign) MPUMposUiConfigurationSummaryFeature summaryFeatures;


@end
