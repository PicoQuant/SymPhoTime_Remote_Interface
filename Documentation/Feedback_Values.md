
# List of Feedback Values (as transmitted by user defined call-back-function)


Read the elements in the list below as construction rules. This means:
An entry like the following example (as taken from the test mode part)
```
  "TCSPCHist"  + <"1", "2">          + "_MaxCounts_"    + <"Sum", "Sync", "Ch1".."Ch8">
```
stands in fact for a "cross product" list with 20 different elements, containing:
```
  "TCSPCHist1_MaxCounts_Sum",
  "TCSPCHist1_MaxCounts_Sync",
  "TCSPCHist1_MaxCounts_Ch1",
  "TCSPCHist1_MaxCounts_Ch2",
  ...
  "TCSPCHist1_MaxCounts_Ch8"

  "TCSPCHist2_MaxCounts_Sum",
  "TCSPCHist2_MaxCounts_Sync",
  "TCSPCHist2_MaxCounts_Ch1",
  "TCSPCHist2_MaxCounts_Ch2",
  ...
  "TCSPCHist2_MaxCounts_Ch8"
```

This results e.g. in more than 330 individual names in test mode.

The list is orderd by measurement modi, online analyses, measurement items and calculation sources. Whether a named feedback value is sent or not during a certain measurement is depending on the the user's selective online choices.

In fact, it isn't predictable at program design time by no means! If e.g. none of the four slots for online analyses is set to FastFLIM during an image measurement, then none of the named values commencing with "FastFLIM" will be transmitted, but the countrates of the detectors installed will always be sent. So, you have to take care of robustness, if you want to rely on the feedback values for controlling purposes.


## Feedbacks in Test-Mode:

```
    Only on start:   "ServerVersion"
    Always:          "sync"
                     "det" + <"1".."8">

                      Analysis    |  Curve Idx          |   Value          |   calculated from...
                     -------------+---------------------+------------------+------------------------------
    if TCSPCHist:    "TCSPCHist"  + <"1", "2">          + "_MaxCounts_"    + <"Sum", "Sync", "Ch1".."Ch8">
                     "TCSPCHist"  + <"1", "2">          + "_SumCounts_"    + <"Sum", "Sync", "Ch1".."Ch8">
                     "TCSPCHist"  + <"1", "2">          + "_AvrRate_"      + <"Sum", "Sync", "Ch1".."Ch8">
                     "TCSPCHist"  + <"1", "2">          + "_FWHM_"         + <"Sum", "Sync", "Ch1".."Ch8">
                     "TCSPCHist"  + <"1", "2">          + "_FastLT_"       + <"Sum", "Sync", "Ch1".."Ch8">

    if TimeTrace:    "TimeTrace"  + <"1", "2">          + "_MaxRate_"      + <"Sum", "Sync", "Ch1".."Ch8">
                     "TimeTrace"  + <"1", "2">          + "_AvrRate_"      + <"Sum", "Sync", "Ch1".."Ch8">
    (equals oldstyle "cps"        + <"1", "2">)

    if FCS:          "FCS"        + <"_A", "_B">        + "_MaxRate_"      + <"Sum", "Sync", "Ch1".."Ch8">
                     "FCS"        + <"_A", "_B">        + "_AvgRate_"      + <"Sum", "Sync", "Ch1".."Ch8">
    (equals oldstyle "cps"        + < "1",  "2">)
                     "FCS"        + <"_A", "_B", "_AB"> + "_G0_"           + <"Sum", "Sync", "Ch1".."Ch8">
                     "FCS"        + <"_A", "_B">        + "_MolCount_"     + <"Sum", "Sync", "Ch1".."Ch8">
                     "FCS"        + <"_A", "_B", "_AB"> + "_MolBrightn_"   + <"Sum", "Sync", "Ch1".."Ch8">
    (equals oldstyle "cpm"        + < "1",  "2">)

    if FastFLIM:     "FastFLIM"   + <"1", "2">          + "_MaxPhotons_"   + <"Sum", "Sync", "Ch1".."Ch8">
    (where the maximum of ("FastFLIM1_MaxPhotons_" + <...>, "FastFLIM2_MaxPhotons_" + <...>) equals oldstyle "maxcpp")
                     "FastFLIM"   + <"1", "2">          + "_AvgPhotons_"   + <"Sum", "Sync", "Ch1".."Ch8">
                     "FastFLIM"   + <"1", "2">          + "_MaxCountRate_" + <"Sum", "Sync", "Ch1".."Ch8">
                     "FastFLIM"   + <"1", "2">          + "_AvgCountRate_" + <"Sum", "Sync", "Ch1".."Ch8">
    (equals oldstyle "cps"        + <"1", "2">)

```

## Feedbacks in Measurement-Mode:

```
    Only on start:   "ServerVersion"
                     "sync"
    Always:          "det" + <"1".."8">

                      Analysis    |  Curve Idx          |   Value          |   calculated from...
                     -------------+---------------------+------------------+------------------------------
    if TCSPCHist:    "TCSPCHist"  + <"1".."4">          + "_MaxCounts_"    + <"Sum", "Sync", "Ch1".."Ch8">
                     "TCSPCHist"  + <"1".."4">          + "_SumCounts_"    + <"Sum", "Sync", "Ch1".."Ch8">
                     "TCSPCHist"  + <"1".."4">          + "_AvrRate_"      + <"Sum", "Sync", "Ch1".."Ch8">
                     "TCSPCHist"  + <"1".."4">          + "_FWHM_"         + <"Sum", "Sync", "Ch1".."Ch8">
                     "TCSPCHist"  + <"1".."4">          + "_FastLT_"       + <"Sum", "Sync", "Ch1".."Ch8">

    if TimeTrace:    "TimeTrace"  + <"1".."4">          + "_MaxRate_"      + <"Sum", "Sync", "Ch1".."Ch8">
                     "TimeTrace"  + <"1".."4">          + "_AvrRate_"      + <"Sum", "Sync", "Ch1".."Ch8">
    (equals oldstyle "cps"                                                 + <"1", "2">)

    if FCS:          "FCS"        + <"1".."4">          + "_MaxRate_"      + <"Sum", "Sync", "Ch1".."Ch8">
                     "FCS"        + <"1".."4">          + "_AvgRate_"      + <"Sum", "Sync", "Ch1".."Ch8">
    (equals oldstyle "cps"                                                 + <"1", "2">)
                     "FCS"        + <"1".."4">          + "_G0_"           + <"Sum", "Sync", "Ch1".."Ch8"> + "_x_" + <"Sum", "Sync", "Ch1".."Ch8">
                     "FCS"        + <"1".."4">          + "_MolCount_"     + <"Sum", "Sync", "Ch1".."Ch8">
                     "FCS"        + <"1".."4">          + "_MolBrightn_"   + <"Sum", "Sync", "Ch1".."Ch8"> + "_x_" + <"Sum", "Sync", "Ch1".."Ch8">
    (equals oldstyle "cpm"                                                 + < "1",                                   "2">)

    if FastFLIM:     "FastFLIM"   + <"1".."4">          + "_MaxPhotons"
    (equals oldstyle "maxcpp")
                     "FastFLIM"   + <"1".."4">          + "_AvgPhotons"
                     "FastFLIM"   + <"1".."4">          + "_MaxCountRate"
                     "FastFLIM"   + <"1".."4">          + "_AvgCountRate"
    (equals oldstyle "cps1")

    if CountRates:   "CountRates" + <"1".."4">          + "_MaxRate_"      + <"Sum", "Sync", "Ch1".."Ch8">
                     "CountRates" + <"1".."4">          + "_AvgRate_"      + <"Sum", "Sync", "Ch1".."Ch8">
    (equals oldstyle "cps"                                                 + <"1", "2">)

```
Consider, that for downward compatibility with SPT32, the upper mentioned old style names are still supported. However, since there may be more than one analysis online, they are no longer unique per feedback frame but may occur
more than once in the frame, embedded in their respective context. So, if you rely on the usage of old style names, you've to take care to know their real context by their neighbour's names.
