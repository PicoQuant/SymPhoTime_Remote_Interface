#File- and Groupname Templates supported by the PicoQuant SymPhoTime Remote Control Client V1.0.8


With the optional parameters, the SymPhoTime Remote Control Client allows for naming of the acquired raw data file (i.e. the Filename) and the desired storing directory (i.e. the Groupname). Additionally an arbitrary comment may be given. Notice, that the filename still has to be unique and unused; Otherwise you will receive an error message and the measurement will not start.

To support the user in construction of unique filenames, the small remote client offers a new feature: The names transferred may contain special token, so called "templates" which will be substituted by SymPhoTime 64 with unique, nonambiguous strings.

Notice:  The discontinued SymPhoTime 32 doesn't support templates!

Currently supported templates are:
```
  TEMPLATESTRING_DATE        = "{$DateCode}"        // Format: YYYYMMDD
  TEMPLATESTRING_DATE_TIME   = "{$DateTimeCode}"    // Format: YYYYMMDDhhmmss
  TEMPLATESTRING_TIME        = "{$TimeCode}"        // Format: hhmmss
  TEMPLATESTRING_TICKS       = "{$TickCode}"        // Format: tttttttttt
```

where "ticks" are the amount of milliseconds since the last bootstrap of the PC hosting the SymPhoTime 64. Don't rely on ticks or time alone if you plan to work on the same workspace in more than one boot-session. On the other hand, it is not very useful to add ticks or the time to a group name, while identifying the date might fit your needs...

Consider a name with a given preambling sequence that should be extended by nonambiguous completions to form unique filenames, allowing for recognition, context adapted sorting, etc.

Notice that there are no restrictions, neither on the count nor on the position of the templates within a filename.

Let's assume the preamble being "NameTest_"; With a measurement started on 04.02.2014 at 1:28:13 PM we might get the filenames:

  +------------------------------------+--------------------------------+
  | Filename with template sent:       | resulting Filename:            |
  +------------------------------------+--------------------------------+
  | NameTest_{$DateCode}               | NameTest_20140204.ptu          |
  | NameTest_{$DateTimeCode}           | NameTest_20140204132813.ptu    |
  | NameTest_{$TimeCode}               | NameTest_132813.ptu            |
  | NameTest_{$TickCode}               | NameTest_0016616009.ptu        |
  +------------------------------------+--------------------------------+
  | FLIM_{$DateCode}_64px_{$TimeCode} | FLIM_20140204_64px�_132813.ptu |
  +------------------------------------+--------------------------------+
