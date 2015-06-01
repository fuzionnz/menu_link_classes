# Menu Link Classes

Menu Link Classes is a little module to let you define some classes
for menu links, and easily turn them on and off in menu list view.

## Usage 

Install the module.

Configure the classes at `admin/config/user-interface/menu-link-classes`
and add a list of classes there, eg

    mobile|Mobile
    desktop|Desktop

There's a setting to let you determine whether the classes are applied
by default (uncheck it from the menu link item to _not_ apply it) or
not applied by default (the reverse).

Once you've saved the settings there, you will see additional
checkboxes at each menu _List Links_ URL.

Checking (or unchecking, depending on the "default" setting) classes
there will apply the class to the menu link items.

## Example

The original use case for this module was to hide some menu items via
media queries. You'd do that something like this:

    ul.menu li.menu-link-classes {
      display: none;
    }
    @media (min-width: 768px) {
      ul.menu li.menu-link-classes.desktop {
        display: list-item;
      }
    }
    @media (max-width: 767px) {
      ul.menu li.menu-link-classes.mobile {
        display: list-item;
      }
    }
