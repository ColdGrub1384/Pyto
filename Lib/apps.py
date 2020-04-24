"""
Open third party apps

This modules contains functions to run actions on third party apps. Some apps support returning the result, but a lot of actions will just return None.

A list of supported apps can be found at https://app-talk.com.
"""

import xcallback
import webbrowser
from urllib.parse import quote


def url_with_params(url, params):

    _url = url

    i = 0
    for (key, item) in params.items():
        if item is not None:
            if i == 0:
                _url = _url + "?"
            else:
                _url = _url + "&"

            _url += key + "=" + quote(item)

        i += 1

    return _url


class Terminology:
    """
    Actions for Terminology.
    """

    def lookup(self, text, action=None) -> str:
        """ Launch Terminology and lookup the text, just as if the user had searched for and selected the text from inside Terminology. """

        args = {}
        args["text"] = text
        args["action"] = action
        return xcallback.open_url(
            url_with_params("terminology://x-callback-url/lookup", args)
        )

    def search(self, text) -> str:
        """ Launches Terminology directly to search for the value of the text parameter. """

        args = {}
        args["text"] = text
        return xcallback.open_url(
            url_with_params("terminology://x-callback-url/search", args)
        )


class RunJavascript:
    """
    Actions for RunJavaScript.
    """

    def run(
        self, script=None, file=None, baseURL=None, input=None, inputName=None
    ) -> str:
        """  """

        args = {}
        args["script"] = script
        args["file"] = file
        args["baseURL"] = baseURL
        args["input"] = input
        args["inputName"] = inputName
        return xcallback.open_url(
            url_with_params("runjavascript://x-callback-url/run", args)
        )


class Blackbox:
    """
    Actions for Blackbox.
    """

    def open(self):
        """ Opens Blackbox. """

        args = {}
        webbrowser.open(url_with_params("blackbox://", args))

    def unlock_meta_challenge(self):
        """ Unlocks a deep link related meta challenge. """

        args = {}
        webbrowser.open(url_with_params("blackbox://meta", args))

    def reset(self):
        """ Presents options for resetting the game. """

        args = {}
        webbrowser.open(url_with_params("blackbox://reset", args))


class Workflow:
    """
    Actions for Workflow.
    """

    def open_workflow(self):
        """ Launch the app to the state when it was last used. """

        args = {}
        webbrowser.open(url_with_params("workflow://", args))

    def create_a_new_workflow(self):
        """ Jump to My Workflows and create an empty new workflow. """

        args = {}
        webbrowser.open(url_with_params("workflow://create-workflow", args))

    def open_a_workflow(self, name=None):
        """ Launch the app to a particular workflow in your collection. """

        args = {}
        args["name"] = name
        webbrowser.open(url_with_params("workflow://open-workflow", args))

    def run_a_workflow(self, name=None, input=None, text=None) -> str:
        """ This functionality may be useful in automation systems that extend beyond Workflow itself, so other apps can run a workflow in your collection. Or, you could utilize this URL in a task manager like OmniFocus or Todoist for running a workflow as one step in a project. """

        args = {}
        args["name"] = name
        args["input"] = input
        args["text"] = text
        return xcallback.open_url(
            url_with_params("workflow://x-callback-url/run-workflow", args)
        )

    def import_a_workflow(self, url=None, name=None, silent=None) -> str:
        """ Workflow also has the ability to accept .wflow files and import them into My Workflows. This is useful, for example, if you would like to share a workflow online and provide a link for others to instantly add it to their library. """

        args = {}
        args["url"] = url
        args["name"] = name
        args["silent"] = silent
        return xcallback.open_url(
            url_with_params("workflow://x-callback-url/import-workflow", args)
        )

    def open_gallery(self):
        """ Open workflow on the main page of the gallery. """

        args = {}
        webbrowser.open(url_with_params("workflow://gallery", args))

    def search_gallery(self, query=None):
        """ Search the gallery """

        args = {}
        args["query"] = query
        webbrowser.open(url_with_params("workflow://gallery/search", args))


class PriceTag:
    """
    Actions for Price Tag.
    """

    def show_explore(self):
        """ Open the Explore tab. """

        args = {}
        webbrowser.open(url_with_params("pricetag://explore", args))

    def show_favorite_list(self):
        """ Open the Favorite tab. """

        args = {}
        webbrowser.open(url_with_params("pricetag://favorites", args))

    def show_price_drop_list(self):
        """ Open the Price Drop tab. """

        args = {}
        webbrowser.open(url_with_params("pricetag://pricedrop", args))

    def show_app_detail_using_url(self, url):
        """ Show the app detail using the App Store URL of the App. """

        args = {}
        args["url"] = url
        webbrowser.open(url_with_params("pricetag://app", args))

    def show_app_detail_using_id(self, id):
        """ Show the app detail using the App Store ID of the App. """

        args = {}
        args["id"] = id
        webbrowser.open(url_with_params("pricetag://app", args))

    def import_apps(self, ids):
        """ Import apps into Price Tag. """

        args = {}
        args["ids"] = ids
        webbrowser.open(url_with_params("pricetag://import", args))

    def search(self, key, p=None):
        """ Searches Price Tag. """

        args = {}
        args["key"] = key
        args["p"] = p
        webbrowser.open(url_with_params("pricetag://search", args))


class DevonthinkToGo:
    """
    Actions for DEVONthink To Go.
    """

    def clip(
        self,
        destination=None,
        title=None,
        comment=None,
        location=None,
        tags=None,
        flagged=None,
        unread=None,
        label=None,
    ) -> str:
        """ Opens the New Document Assistant, pre- filled with the provided data. """

        args = {}
        args["destination"] = destination
        args["title"] = title
        args["comment"] = comment
        args["location"] = location
        args["tags"] = tags
        args["flagged"] = flagged
        args["unread"] = unread
        args["label"] = label
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/clip", args)
        )

    def create_bookmark(
        self,
        destination=None,
        title=None,
        comment=None,
        location=None,
        tags=None,
        flagged=None,
        unread=None,
        label=None,
    ) -> str:
        """ Creates a new bookmark. """

        args = {}
        args["destination"] = destination
        args["title"] = title
        args["comment"] = comment
        args["location"] = location
        args["tags"] = tags
        args["flagged"] = flagged
        args["unread"] = unread
        args["label"] = label
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/createbookmark", args)
        )

    def create_group(
        self,
        destination=None,
        title=None,
        comment=None,
        location=None,
        tags=None,
        flagged=None,
        unread=None,
        label=None,
    ) -> str:
        """ Creates a new group. """

        args = {}
        args["destination"] = destination
        args["title"] = title
        args["comment"] = comment
        args["location"] = location
        args["tags"] = tags
        args["flagged"] = flagged
        args["unread"] = unread
        args["label"] = label
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/creategroup", args)
        )

    def create_text(
        self,
        destination=None,
        title=None,
        comment=None,
        location=None,
        tags=None,
        flagged=None,
        unread=None,
        label=None,
    ) -> str:
        """ Creates a new plain text document. """

        args = {}
        args["destination"] = destination
        args["title"] = title
        args["comment"] = comment
        args["location"] = location
        args["tags"] = tags
        args["flagged"] = flagged
        args["unread"] = unread
        args["label"] = label
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/createtext", args)
        )

    def create_markdown(
        self,
        destination=None,
        title=None,
        comment=None,
        location=None,
        tags=None,
        flagged=None,
        unread=None,
        label=None,
    ) -> str:
        """ Creates a new Markdown document. """

        args = {}
        args["destination"] = destination
        args["title"] = title
        args["comment"] = comment
        args["location"] = location
        args["tags"] = tags
        args["flagged"] = flagged
        args["unread"] = unread
        args["label"] = label
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/createmarkdown", args)
        )

    def create_webarchive(
        self,
        destination=None,
        title=None,
        comment=None,
        location=None,
        tags=None,
        flagged=None,
        unread=None,
        label=None,
    ) -> str:
        """ Creates a new webarchive. """

        args = {}
        args["destination"] = destination
        args["title"] = title
        args["comment"] = comment
        args["location"] = location
        args["tags"] = tags
        args["flagged"] = flagged
        args["unread"] = unread
        args["label"] = label
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/createwebarchive", args)
        )

    def import_clipboard(self) -> str:
        """ Imports data from the pasteboard to the global inbox. """

        args = {}
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/import-clipboard", args)
        )

    def create_document(
        self,
        uti,
        source,
        destination=None,
        title=None,
        comment=None,
        location=None,
        tags=None,
        flagged=None,
        unread=None,
        label=None,
    ) -> str:
        """ Creates a new document from UTI and file data. """

        args = {}
        args["uti"] = uti
        args["source"] = source
        args["destination"] = destination
        args["title"] = title
        args["comment"] = comment
        args["location"] = location
        args["tags"] = tags
        args["flagged"] = flagged
        args["unread"] = unread
        args["label"] = label
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/document", args)
        )

    def search(self, query, scope=None) -> str:
        """ Search DEVONthink To Go and show or retrieve the results. """

        args = {}
        args["query"] = query
        args["scope"] = scope
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/search", args)
        )

    def create_html(
        self,
        source,
        destination=None,
        title=None,
        comment=None,
        location=None,
        tags=None,
        flagged=None,
        unread=None,
        label=None,
    ) -> str:
        """ Creates a new HTML document. """

        args = {}
        args["source"] = source
        args["destination"] = destination
        args["title"] = title
        args["comment"] = comment
        args["location"] = location
        args["tags"] = tags
        args["flagged"] = flagged
        args["unread"] = unread
        args["label"] = label
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/createhtml", args)
        )

    def create_image(
        self,
        source,
        destination=None,
        title=None,
        comment=None,
        location=None,
        tags=None,
        flagged=None,
        unread=None,
        label=None,
    ) -> str:
        """ Creates a new image. """

        args = {}
        args["source"] = source
        args["destination"] = destination
        args["title"] = title
        args["comment"] = comment
        args["location"] = location
        args["tags"] = tags
        args["flagged"] = flagged
        args["unread"] = unread
        args["label"] = label
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/createimage", args)
        )

    def update_item(
        self,
        uuid,
        source=None,
        destination=None,
        text=None,
        title=None,
        comment=None,
        location=None,
        tags=None,
        flagged=None,
        unread=None,
        label=None,
    ) -> str:
        """ Updates an existing item. """

        args = {}
        args["uuid"] = uuid
        args["source"] = source
        args["destination"] = destination
        args["text"] = text
        args["title"] = title
        args["comment"] = comment
        args["location"] = location
        args["tags"] = tags
        args["flagged"] = flagged
        args["unread"] = unread
        args["label"] = label
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/update", args)
        )

    def retrieve_document_metadata(self, uuid) -> str:
        """ Returns selected metadata of a document as JSON object. """

        args = {}
        args["uuid"] = uuid
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/item", args)
        )

    def retrieve_document_data(self, uuid) -> str:
        """ Returns selected metadata of a document as JSON object. """

        args = {}
        args["uuid"] = uuid
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/content", args)
        )

    def retrieve_group_contents(self, uuid) -> str:
        """ Returns a JSON array describing the contents of a group. """

        args = {}
        args["uuid"] = uuid
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/list", args)
        )

    def get_selected_items_link(self) -> str:
        """ Returns the item link for the currently selected document. """

        args = {}
        return xcallback.open_url(
            url_with_params("x-devonthink://x-callback-url/get-itemlink", args)
        )


class Spark:
    """
    Actions for Spark.
    """

    def compose(self, subject=None, body=None, recipient=None):
        """ Open a new email draft in Spark """

        args = {}
        args["subject"] = subject
        args["body"] = body
        args["recipient"] = recipient
        webbrowser.open(url_with_params("readdle-spark://compose", args))


class Calca:
    """
    Actions for Calca.
    """

    def create(self, body, title) -> str:
        """ Create a new document with the given name and contents. It is saved in the active storage location in the folder that was last browsed. The document is opened and set to edit. """

        args = {}
        args["body"] = body
        args["title"] = title
        return xcallback.open_url(
            url_with_params("calca://x-callback-url/create", args)
        )

    def calc(self, body) -> str:
        """ Calc a block of text and return it to the calling application. The text is computed in the same way as if it were opened in Calca: all lines with => are computed and the values written out. """

        args = {}
        args["body"] = body
        return xcallback.open_url(url_with_params("calc://x-callback-url/calc", args))


class Launcher:
    """
    Actions for Launcher.
    """

    def open_launcher(self, idx=None):
        """ Open launcher app. """

        args = {}
        args["idx"] = idx
        webbrowser.open(url_with_params("launcher://", args))

    def add_new_launcher(self, name, url, iconB64=None, idx=None) -> str:
        """ Add a new launcher. """

        args = {}
        args["name"] = name
        args["url"] = url
        args["iconB64"] = iconB64
        args["idx"] = idx
        return xcallback.open_url(
            url_with_params("launcher://x-callback-url/addnew", args)
        )


class Tally2:
    """
    Actions for Tally 2.
    """

    def open(self, title) -> str:
        """  """

        args = {}
        args["title"] = title
        return xcallback.open_url(url_with_params("tally2://x-callback-url/open", args))

    def get(self, title, retParam=None) -> str:
        """ Lookup the tally based on the title parameter, and call the x-success parameter URL with the current value of the tally added as a parameter. """

        args = {}
        args["title"] = title
        args["retParam"] = retParam
        return xcallback.open_url(url_with_params("tally2://x-callback-url/get", args))

    def increment(self, title, retParam=None) -> str:
        """ Lookup the tally based on the title parameter, and increment it. Increment will be based on the configuration of the tally – so if it is set to step by 5, the increment will be by five. """

        args = {}
        args["title"] = title
        args["retParam"] = retParam
        return xcallback.open_url(
            url_with_params("tally2://x-callback-url/increment", args)
        )

    def decrement(self, title, retParam=None) -> str:
        """ Lookup the tally based on the title parameter, and decrement it. Decrement will be based on the configuration of the tally – so if it is set to step by 5, the decrement will be by five. """

        args = {}
        args["title"] = title
        args["retParam"] = retParam
        return xcallback.open_url(
            url_with_params("tally2://x-callback-url/decrement", args)
        )

    def reset(self, title, retParam=None) -> str:
        """ Lookup the tally based on the title parameter, and reset it to it's initial value. """

        args = {}
        args["title"] = title
        args["retParam"] = retParam
        return xcallback.open_url(
            url_with_params("tally2://x-callback-url/reset", args)
        )


class GoogleMaps:
    """
    Actions for Google Maps.
    """

    def display_a_map(self, center=None, mapmode=None, views=None, zoom=None) -> str:
        """ Display the map at a specified zoom level and location. You can also overlay other views on top of your map, or display Street View imagery. """

        args = {}
        args["center"] = center
        args["mapmode"] = mapmode
        args["views"] = views
        args["zoom"] = zoom
        return xcallback.open_url(
            url_with_params("comgooglemaps-x-callback://x-callback-url", args)
        )

    def search(self, q=None, center=None, mapmode=None, views=None, zoom=None) -> str:
        """ Display search queries in a specified viewport location. """

        args = {}
        args["q"] = q
        args["center"] = center
        args["mapmode"] = mapmode
        args["views"] = views
        args["zoom"] = zoom
        return xcallback.open_url(
            url_with_params("comgooglemaps-x-callback://x-callback-url", args)
        )

    def directions(self, saddr=None, daddr=None, directionsmode=None) -> str:
        """ Request and display directions between two locations. """

        args = {}
        args["saddr"] = saddr
        args["daddr"] = daddr
        args["directionsmode"] = directionsmode
        return xcallback.open_url(
            url_with_params("comgooglemaps-x-callback://x-callback-url", args)
        )


class Shopi:
    """
    Actions for Shopi.
    """

    def show_all_lists(self) -> str:
        """ Ensure the main display is showing the view showing all shopping lists. """

        args = {}
        return xcallback.open_url(
            url_with_params("shopi://x-callback-url/show-lists", args)
        )

    def show_list(self, name) -> str:
        """ Show a specific list. """

        args = {}
        args["name"] = name
        return xcallback.open_url(
            url_with_params("shopi://x-callback-url/show-list", args)
        )

    def create_list(self, name) -> str:
        """ Create a new list """

        args = {}
        args["name"] = name
        return xcallback.open_url(
            url_with_params("shopi://x-callback-url/create-list", args)
        )

    def add_list_item(self, list, name, amount=None, crossed=None) -> str:
        """ Add an item to a list (or the currently displayed list if not specified). """

        args = {}
        args["list"] = list
        args["name"] = name
        args["amount"] = amount
        args["crossed"] = crossed
        return xcallback.open_url(
            url_with_params("shopi://x-callback-url/add-item", args)
        )

    def clear_list_items(self, name, crossed_only=None) -> str:
        """ Clear items from a list. """

        args = {}
        args["name"] = name
        args["crossed-only"] = crossed_only
        return xcallback.open_url(
            url_with_params("shopi://x-callback-url/clear-list", args)
        )


class WorkingCopy:
    """
    Actions for Working Copy.
    """

    def writing_files(
        self,
        key,
        repo=None,
        path=None,
        text=None,
        base64=None,
        askcommit=None,
        append=None,
        overwrite=None,
        filename=None,
        uti=None,
    ) -> str:
        """ Write to existing or new files. """

        args = {}
        args["key"] = key
        args["repo"] = repo
        args["path"] = path
        args["text"] = text
        args["base64"] = base64
        args["askcommit"] = askcommit
        args["append"] = append
        args["overwrite"] = overwrite
        args["filename"] = filename
        args["uti"] = uti
        return xcallback.open_url(
            url_with_params("working-copy://x-callback-url/write", args)
        )

    def reading_files(self, key, repo=None, path=None, base64=None, uti=None) -> str:
        """ You can get the contents of text or binary files. """

        args = {}
        args["key"] = key
        args["repo"] = repo
        args["path"] = path
        args["base64"] = base64
        args["uti"] = uti
        return xcallback.open_url(
            url_with_params("working-copy://x-callback-url/read", args)
        )

    def moving_files(self, key, repo, source, destination) -> str:
        """ Move or rename files within a repository. """

        args = {}
        args["key"] = key
        args["repo"] = repo
        args["source"] = source
        args["destination"] = destination
        return xcallback.open_url(
            url_with_params("working-copy://x-callback-url/move", args)
        )

    def committing_changes(self, key, repo, message, path=None, limit=None) -> str:
        """ Commit files, directories or entire repository. """

        args = {}
        args["key"] = key
        args["repo"] = repo
        args["path"] = path
        args["message"] = message
        args["limit"] = limit
        return xcallback.open_url(
            url_with_params("working-copy://x-callback-url/commit", args)
        )

    def push_to_remote(self, key, repo, remote=None) -> str:
        """ Send commits back to the origin remote. """

        args = {}
        args["key"] = key
        args["repo"] = repo
        args["remote"] = remote
        return xcallback.open_url(
            url_with_params("working-copy://x-callback-url/push", args)
        )

    def pull_from_remote(self, key, repo, remote=None) -> str:
        """ Fetch and merge changes from remote. """

        args = {}
        args["key"] = key
        args["repo"] = repo
        args["remote"] = remote
        return xcallback.open_url(
            url_with_params("working-copy://x-callback-url/pull", args)
        )


class MultiTimer:
    """
    Actions for MultiTimer.
    """

    def start_timer(self, name, board=None) -> str:
        """  """

        args = {}
        args["name"] = name
        args["board"] = board
        return xcallback.open_url(
            url_with_params("multitimer://x-callback-url/start-timer", args)
        )

    def stop_timer(self, name, board=None) -> str:
        """  """

        args = {}
        args["name"] = name
        args["board"] = board
        return xcallback.open_url(
            url_with_params("multitimer://x-callback-url/stop-timer", args)
        )

    def pause_timer(self, name, board=None) -> str:
        """  """

        args = {}
        args["name"] = name
        args["board"] = board
        return xcallback.open_url(
            url_with_params("multitimer://x-callback-url/pause-timer", args)
        )

    def resume_timer(self, name, board=None) -> str:
        """  """

        args = {}
        args["name"] = name
        args["board"] = board
        return xcallback.open_url(
            url_with_params("multitimer://x-callback-url/resume-timer", args)
        )

    def run_command(self, name) -> str:
        """  """

        args = {}
        args["name"] = name
        return xcallback.open_url(
            url_with_params("multitimer://x-callback-url/run-command", args)
        )


class Todoist:
    """
    Actions for Todoist.
    """

    def open(self):
        """ Opens Todoist. """

        args = {}
        webbrowser.open(url_with_params("todoist://", args))

    def open_today(self):
        """ Opens the today view. """

        args = {}
        webbrowser.open(url_with_params("todoist://today", args))

    def open_next_7_days(self):
        """ Opens the next 7 days view. """

        args = {}
        webbrowser.open(url_with_params("todoist://next7days", args))

    def open_profile(self):
        """ Opens the profile view. """

        args = {}
        webbrowser.open(url_with_params("todoist://profile", args))

    def open_inbox(self):
        """ Opens the inbox view. """

        args = {}
        webbrowser.open(url_with_params("todoist://inbox", args))

    def open_team_inbox(self):
        """ Opens the team inbox view. If the user doesn’t have a business account (access to team inbox), it will show an alert saying that he/she doesn’t have access to the team inbox because he/she doesn’t have a business account and will be redirected automatically to the inbox view. """

        args = {}
        webbrowser.open(url_with_params("todoist://teaminbox", args))

    def add_task(self, content=None, date=None, priority=None):
        """ Opens the add task view to add a new task to Todoist. """

        args = {}
        args["content"] = content
        args["date"] = date
        args["priority"] = priority
        webbrowser.open(url_with_params("todoist://addtask", args))

    def projects(self):
        """ Opens the projects view (shows all projects). """

        args = {}
        webbrowser.open(url_with_params("todoist://projects", args))

    def open_project(self, id):
        """ Opens a specific project using the id of the project. """

        args = {}
        args["id"] = id
        webbrowser.open(url_with_params("todoist://project", args))

    def labels(self):
        """ Opens the labels view (shows all labels). """

        args = {}
        webbrowser.open(url_with_params("todoist://labels", args))

    def open_label(self, id):
        """ Opens a specific label using the id of the label. """

        args = {}
        args["id"] = id
        webbrowser.open(url_with_params("todoist://label", args))

    def filters(self):
        """ Opens the filters view (shows all filters). """

        args = {}
        webbrowser.open(url_with_params("todoist://filters", args))

    def open_filter(self, id):
        """ Opens a specific filter using the id of the filter. """

        args = {}
        args["id"] = id
        webbrowser.open(url_with_params("todoist://filter", args))

    def search(self, query):
        """ Used to search in the Todoist application. """

        args = {}
        args["query"] = query
        webbrowser.open(url_with_params("todoist://search", args))


class Ulysses:
    """
    Actions for Ulysses.
    """

    def new_sheet(self, text=None, group=None, format=None, index=None) -> str:
        """ Creates a new sheet. """

        args = {}
        args["text"] = text
        args["group"] = group
        args["format"] = format
        args["index"] = index
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/new-sheet", args)
        )

    def new_group(self, name=None, parent=None, index=None) -> str:
        """ Creates a new group. """

        args = {}
        args["name"] = name
        args["parent"] = parent
        args["index"] = index
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/new-group", args)
        )

    def insert(
        self, id=None, text=None, format=None, position=None, newline=None
    ) -> str:
        """ Inserts or appends text to a sheet. """

        args = {}
        args["id"] = id
        args["text"] = text
        args["format"] = format
        args["position"] = position
        args["newline"] = newline
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/insert", args)
        )

    def attach_note(self, id=None, text=None, format=None) -> str:
        """ Creates a new note attachment on a sheet. """

        args = {}
        args["id"] = id
        args["text"] = text
        args["format"] = format
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/attach-note", args)
        )

    def update_note(self, id=None, text=None, format=None, index=None) -> str:
        """ Changes an existing note attachment on a sheet. Requires authorization. """

        args = {}
        args["id"] = id
        args["text"] = text
        args["format"] = format
        args["index"] = index
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/update-note", args)
        )

    def remove_note(self, id=None, index=None) -> str:
        """ Removes a note attachment from a sheet. Requires authorization. """

        args = {}
        args["id"] = id
        args["index"] = index
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/remove-note", args)
        )

    def attach_image(self, id=None, image=None, format=None, filename=None) -> str:
        """ Creates a new image attachment on a sheet. """

        args = {}
        args["id"] = id
        args["image"] = image
        args["format"] = format
        args["filename"] = filename
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/attach-image", args)
        )

    def attach_keywords(self, id=None, keywords=None) -> str:
        """ Adds one or more keywords to a sheet. """

        args = {}
        args["id"] = id
        args["keywords"] = keywords
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/attach-keywords", args)
        )

    def remove_keywords(self, id=None, keywords=None) -> str:
        """ Removes one or more keywords from a sheet. Requires authorization. """

        args = {}
        args["id"] = id
        args["keywords"] = keywords
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/remove-keywords", args)
        )

    def set_group_title(self, group=None, title=None) -> str:
        """ Changes the title of a group. Requires authorization. """

        args = {}
        args["group"] = group
        args["title"] = title
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/set-group-title", args)
        )

    def set_sheet_title(self, sheet=None, type=None, title=None) -> str:
        """ Changes the first paragraph of a sheet. Requires authorization. If the sheet has a first paragraph with the requested type, the paragraph contents will be changed (a heading replaces any existing heading). Otherwise, a new paragraph with the requested type and contents will be inserted at the beginning of the sheet. """

        args = {}
        args["sheet"] = sheet
        args["type"] = type
        args["title"] = title
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/set-sheet-title", args)
        )

    def move(self, id=None, targetGroup=None, index=None) -> str:
        """ Moves an item (sheet or group) to a target group and/or to a new position. Requires authorization. """

        args = {}
        args["id"] = id
        args["targetGroup"] = targetGroup
        args["index"] = index
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/move", args)
        )

    def copy(self, id=None, targetGroup=None, index=None) -> str:
        """ Copies an item (sheet or group) to a target group and/or to a new position. """

        args = {}
        args["id"] = id
        args["targetGroup"] = targetGroup
        args["index"] = index
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/copy", args)
        )

    def trash(self, id=None) -> str:
        """ Moves an item (sheet or group) to the trash. Requires authorization. """

        args = {}
        args["id"] = id
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/trash", args)
        )

    def get_item_group(self, id=None, recursive=None) -> str:
        """ Retrieves information about a group. Requires authorization. """

        args = {}
        args["id"] = id
        args["recursive"] = recursive
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/get-item", args)
        )

    def get_item_sheet(self, id=None) -> str:
        """ Retrieves information about a sheet. Requires authorization. """

        args = {}
        args["id"] = id
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/get-item", args)
        )

    def get_root_items(self, recursive=None) -> str:
        """ Retrieves information about the root sections. Can be used to get a full listing of the entire Ulysses library. Requires authorization. """

        args = {}
        args["recursive"] = recursive
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/get-root-items", args)
        )

    def read_sheet(self, id=None, text=None, Open=None) -> str:
        """ Retrieves the contents (text, notes, keywords) of a sheet. Requires authorization. """

        args = {}
        args["id"] = id
        args["text"] = text
        args["Open"] = Open
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/read-sheet", args)
        )

    def open_all(self) -> str:
        """ Opens the special “All” group """

        args = {}
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/open-all", args)
        )

    def open_recent(self) -> str:
        """ Opens the special “Last 7 days” group """

        args = {}
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/open-recent", args)
        )

    def open_favorites(self) -> str:
        """ Opens the special “Favorites” group """

        args = {}
        return xcallback.open_url(
            url_with_params("ulysses://x-callback-url/open-favorites", args)
        )


class Airmail:
    """
    Actions for Airmail.
    """

    def compose(
        self,
        subject=None,
        _from=None,
        to=None,
        cc=None,
        bcc=None,
        plainBody=None,
        htmlBody=None,
    ):
        """ Open a new email draft in Airmail """

        args = {}
        args["subject"] = subject
        args["from"] = _from
        args["to"] = to
        args["cc"] = cc
        args["bcc"] = bcc
        args["plainBody"] = plainBody
        args["htmlBody"] = htmlBody
        webbrowser.open(url_with_params("airmail://compose", args))


class Chrome:
    """
    Actions for Chrome.
    """

    def open_url(self, url) -> str:
        """ Open the given URL """

        args = {}
        args["url"] = url
        return xcallback.open_url(
            url_with_params("googlechrome-x-callback://x-callback-url/open", args)
        )


class StoryPlanner:
    """
    Actions for Story Planner.
    """

    def add(self, title) -> str:
        """ Add a new project. """

        args = {}
        args["title"] = title
        return xcallback.open_url(
            url_with_params("storyplanner://x-callback-url/add", args)
        )

    def project_by_title(self, title, tab=None) -> str:
        """ Open an existing project by title. """

        args = {}
        args["title"] = title
        args["tab"] = tab
        return xcallback.open_url(
            url_with_params("storyplanner://x-callback-url/project", args)
        )

    def project_by_identifier(self, id, tab=None) -> str:
        """ Open an existing project by identifier. You can get the identifier within the project by opening export options and choosing "Copy identifier". """

        args = {}
        args["id"] = id
        args["tab"] = tab
        return xcallback.open_url(
            url_with_params("storyplanner://x-callback-url/project", args)
        )


class TwoDo:
    """
    Actions for 2Do.
    """

    def show_all_focus_list(self) -> str:
        """  """

        args = {}
        return xcallback.open_url(
            url_with_params("twodo://x-callback-url/showAll", args)
        )

    def show_today_focus_list(self) -> str:
        """  """

        args = {}
        return xcallback.open_url(
            url_with_params("twodo://x-callback-url/showToday", args)
        )

    def show_starred_focus_list(self) -> str:
        """  """

        args = {}
        return xcallback.open_url(
            url_with_params("twodo://x-callback-url/showStarred", args)
        )

    def show_scheduled_focus_list(self) -> str:
        """  """

        args = {}
        return xcallback.open_url(
            url_with_params("twodo://x-callback-url/showScheduled", args)
        )

    def show_list(self, name=None) -> str:
        """ Show List with a given name. """

        args = {}
        args["name"] = name
        return xcallback.open_url(
            url_with_params("twodo://x-callback-url/showList", args)
        )

    def add_new_task(self, ignoreDefaults=None) -> str:
        """ Launch the app with the New Task Screen. """

        args = {}
        args["ignoreDefaults"] = ignoreDefaults
        return xcallback.open_url(
            url_with_params("twodo://x-callback-url/addNewTask", args)
        )

    def search(self, text=None) -> str:
        """ Launch the app with Search pre filled. """

        args = {}
        args["text"] = text
        return xcallback.open_url(
            url_with_params("twodo://x-callback-url/search", args)
        )

    def get_task_unique_identifier(
        self, task=None, forList=None, saveInClipboard=None
    ) -> str:
        """ Returns the internally used unique identifier for the task. x-success is filled with the a key named ”uid” """

        args = {}
        args["task"] = task
        args["forList"] = forList
        args["saveInClipboard"] = saveInClipboard
        return xcallback.open_url(
            url_with_params("twodo://x-callback-url/getTaskID", args)
        )

    def paste_text(self, text, inProject=None, forList=None) -> str:
        """ Turn text into tasks. """

        args = {}
        args["text"] = text
        args["inProject"] = inProject
        args["forList"] = forList
        return xcallback.open_url(url_with_params("twodo://x-callback-url/paste", args))

    def add_task(
        self,
        task=None,
        type=None,
        forList=None,
        forParentName=None,
        forParentTask=None,
        note=None,
        priority=None,
        starred=None,
        tags=None,
        locations=None,
        due=None,
        dueTime=None,
        start=None,
        repeat=None,
        action=None,
        picture=None,
        audio=None,
        ignoreDefaults=None,
        useQuickEntry=None,
        saveInClipboard=None,
    ) -> str:
        """  """

        args = {}
        args["task"] = task
        args["type"] = type
        args["forList"] = forList
        args["forParentName"] = forParentName
        args["forParentTask"] = forParentTask
        args["note"] = note
        args["priority"] = priority
        args["starred"] = starred
        args["tags"] = tags
        args["locations"] = locations
        args["due"] = due
        args["dueTime"] = dueTime
        args["start"] = start
        args["repeat"] = repeat
        args["action"] = action
        args["picture"] = picture
        args["audio"] = audio
        args["ignoreDefaults"] = ignoreDefaults
        args["useQuickEntry"] = useQuickEntry
        args["saveInClipboard"] = saveInClipboard
        return xcallback.open_url(url_with_params("twodo://x-callback-url/add", args))


class Infuse:
    """
    Actions for Infuse.
    """

    def open_infuse(self):
        """ Opens Infuse. """

        args = {}
        webbrowser.open(url_with_params("infuse://", args))

    def play_video_in_infuse(self, url) -> str:
        """ Plays the video from the provided URL in Infuse. """

        args = {}
        args["url"] = url
        return xcallback.open_url(url_with_params("infuse://x-callback-url/play", args))


class Instapaper:
    """
    Actions for Instapaper.
    """

    def add_url(self, url=None) -> str:
        """ Add the URL to Instapaper. """

        args = {}
        args["url"] = url
        return xcallback.open_url(
            url_with_params("x-callback-instapaper://x-callback-url/add", args)
        )


class Shortcuts:
    """
    Actions for Shortcuts.
    """

    def open_shortcuts(self):
        """ Launch the app to the state when it was last used. """

        args = {}
        webbrowser.open(url_with_params("shortcuts://", args))

    def create_a_new_shortcut(self):
        """ Jump to the shortcut editor and to create a new, empty shortcut. """

        args = {}
        webbrowser.open(url_with_params("shortcuts://create-shortcut", args))

    def open_a_shortcut(self, name):
        """ Launch the app to a particular shortcut in your collection. """

        args = {}
        args["name"] = name
        webbrowser.open(url_with_params("shortcuts://open-shortcut", args))

    def run_a_shortcut(self, name, input=None, text=None) -> str:
        """ This functionality may be useful in automation systems that extend beyond Shortcuts itself, so that other apps can run a shortcut in your collection. Or you could use the Shortcuts URL scheme in a task manager like OmniFocus or Todoist for running a shortcut as one step in a project. """

        args = {}
        args["name"] = name
        args["input"] = input
        args["text"] = text
        return xcallback.open_url(
            url_with_params("shortcuts://x-callback-url/run-shortcut", args)
        )

    def import_a_shortcut(self, url, name=None, silent=None) -> str:
        """ You can import .shortcut files into the Shortcuts app and add them to your collection. This is useful, for example, if you want to share a shortcut online and provide a link for others to quickly add it to their library. """

        args = {}
        args["url"] = url
        args["name"] = name
        args["silent"] = silent
        return xcallback.open_url(
            url_with_params("shortcuts://x-callback-url/import-shortcut", args)
        )

    def open_gallery(self):
        """ Open Shortcuts on the main page of the Gallery. """

        args = {}
        webbrowser.open(url_with_params("shortcuts://gallery", args))

    def search_gallery(self, query):
        """ Search the gallery """

        args = {}
        args["query"] = query
        webbrowser.open(url_with_params("shortcuts://gallery/search", args))


class Gladys:
    """
    Actions for Gladys.
    """

    def paste_clipboard(self, title=None, labels=None, note=None) -> str:
        """ Paste clipboard into Gladys """

        args = {}
        args["title"] = title
        args["labels"] = labels
        args["note"] = note
        return xcallback.open_url(
            url_with_params("gladys://x-callback-url/paste-clipboard", args)
        )


class DictCc:
    """
    Actions for dict.cc.
    """

    def translate(self, word=None, language_pair=None) -> str:
        """ Translate a phrase in dict.cc. """

        args = {}
        args["word"] = word
        args["language-pair"] = language_pair
        return xcallback.open_url(
            url_with_params("dictcc-x-callback://x-callback-url/translate", args)
        )


class Timepage:
    """
    Actions for Timepage.
    """

    def add_event(self, title=None, day=None) -> str:
        """  """

        args = {}
        args["title"] = title
        args["day"] = day
        return xcallback.open_url(
            url_with_params("timepage://x-callback-url/add_event", args)
        )

    def open_event(self, event=None):
        """ Open Timepage and show a specified event. """

        args = {}
        args["event"] = event
        webbrowser.open(url_with_params("timpage://open_event", args))

    def open_event_map(self, event=None):
        """ Open Timepage and show a specified event on the map """

        args = {}
        args["event"] = event
        webbrowser.open(url_with_params("timpage://open_event_map", args))

    def open_day(self, day=None):
        """ Open Timepage and show a specified day. """

        args = {}
        args["day"] = day
        webbrowser.open(url_with_params("timepage://open_day", args))

    def open_week(self, week=None):
        """ Open Timepage and show a specified week """

        args = {}
        args["week"] = week
        webbrowser.open(url_with_params("timepage://open_week", args))

    def open_month(self, month=None):
        """ Open Timepage and show a specified month """

        args = {}
        args["month"] = month
        webbrowser.open(url_with_params("timepage://open_month", args))

    def open_weather_for_a_day(self, day=None):
        """ Open Timepage and show weather for a specified day. """

        args = {}
        args["day"] = day
        webbrowser.open(url_with_params("timepage://open_weather", args))

    def open_weather_for_a_week(self, week=None):
        """ Open Timepage and show weather for a specified week. """

        args = {}
        args["week"] = week
        webbrowser.open(url_with_params("timepage://open_weather", args))

    def search(self, query=None):
        """ Open Timepage and show search results for the specified search terms. """

        args = {}
        args["query"] = query
        webbrowser.open(url_with_params("timepage://search", args))

    def get_event(self, event=None) -> str:
        """ Get a specified event and return its details via a specified callback URL. """

        args = {}
        args["event"] = event
        return xcallback.open_url(
            url_with_params("timepage://x-callback-url/get_event", args)
        )


class Gmail:
    """
    Actions for Gmail.
    """

    def compose(self, subject=None, body=None, to=None, cc=None, bcc=None) -> str:
        """ Compose a mail. """

        args = {}
        args["subject"] = subject
        args["body"] = body
        args["to"] = to
        args["cc"] = cc
        args["bcc"] = bcc
        return xcallback.open_url(
            url_with_params("googlegmail-x-callback://x-callback-url", args)
        )


class OmniFocus:
    """
    Actions for OmniFocus 3.
    """

    def add(
        self,
        name,
        note=None,
        attachment=None,
        attachment_name=None,
        parallel=None,
        flag=None,
        defer=None,
        due=None,
        project=None,
        context=None,
        autocomplete=None,
        estimate=None,
        reveal_new_items=None,
        repeat_method=None,
        completed=None,
    ) -> str:
        """ Add a task to OmniFocus """

        args = {}
        args["name"] = name
        args["note"] = note
        args["attachment"] = attachment
        args["attachment-name"] = attachment_name
        args["parallel"] = parallel
        args["flag"] = flag
        args["defer"] = defer
        args["due"] = due
        args["project"] = project
        args["context"] = context
        args["autocomplete"] = autocomplete
        args["estimate"] = estimate
        args["reveal-new-items"] = reveal_new_items
        args["repeat-method"] = repeat_method
        args["completed"] = completed
        return xcallback.open_url(
            url_with_params("omnifoucs://x-callback-url/add", args)
        )

    def inbox_perspective(self):
        """  """

        args = {}
        webbrowser.open(url_with_params("omnifocus:///inbox", args))

    def flagged_perspective(self):
        """  """

        args = {}
        webbrowser.open(url_with_params("omnifocus:///flagged", args))

    def project_perspective(self):
        """  """

        args = {}
        webbrowser.open(url_with_params("omnifocus:///projects", args))

    def contexts_perspective(self):
        """  """

        args = {}
        webbrowser.open(url_with_params("omnifocus:///contexts", args))

    def past_forecast(self):
        """  """

        args = {}
        webbrowser.open(url_with_params("omnifocus:///past", args))

    def today_forecast(self):
        """  """

        args = {}
        webbrowser.open(url_with_params("omnifocus:///today", args))

    def soon_forecast(self):
        """  """

        args = {}
        webbrowser.open(url_with_params("omnifocus:///soon", args))


class Byword:
    """
    Actions for Byword.
    """

    def new(self, location=None, path=None, name=None, text=None) -> str:
        """ Create a new file in Byword. """

        args = {}
        args["location"] = location
        args["path"] = path
        args["name"] = name
        args["text"] = text
        return xcallback.open_url(url_with_params("byword://x-callback-url/new", args))

    def open(self, location=None, path=None, name=None) -> str:
        """ Open an existing file. Fails if the file does not exist. """

        args = {}
        args["location"] = location
        args["path"] = path
        args["name"] = name
        return xcallback.open_url(url_with_params("byword://x-callback-url/open", args))

    def append(self, location=None, path=None, name=None, text=None) -> str:
        """ Append content to an existing file. If the file does not exist a new one is created. """

        args = {}
        args["location"] = location
        args["path"] = path
        args["name"] = name
        args["text"] = text
        return xcallback.open_url(
            url_with_params("byword://x-callback-url/append", args)
        )

    def prepend(self, location=None, path=None, name=None, text=None) -> str:
        """ Prepend content to an existing file. If the file does not exist a new one is created. """

        args = {}
        args["location"] = location
        args["path"] = path
        args["name"] = name
        args["text"] = text
        return xcallback.open_url(
            url_with_params("byword://x-callback-url/prepend", args)
        )

    def replace(self, location=None, path=None, name=None, text=None) -> str:
        """ Replace the contents of an existing file. If the file doesn’t exist a new one is created. """

        args = {}
        args["location"] = location
        args["path"] = path
        args["name"] = name
        args["text"] = text
        return xcallback.open_url(
            url_with_params("byword://x-callback-url/replace", args)
        )


class Outlinely:
    """
    Actions for Outlinely.
    """

    def open(self, path, storage=None) -> str:
        """ Open an outline. """

        args = {}
        args["path"] = path
        args["storage"] = storage
        return xcallback.open_url(
            url_with_params("outlinely://x-callback-url/open", args)
        )

    def new(self, text, group, title=None, storage=None, type=None) -> str:
        """ Create a new outline. """

        args = {}
        args["text"] = text
        args["group"] = group
        args["title"] = title
        args["storage"] = storage
        args["type"] = type
        return xcallback.open_url(
            url_with_params("outlinely://x-callback-url/new", args)
        )

    def insert(self, text, path, storage=None, parent=None, mode=None) -> str:
        """ Insert text into an existing outline. """

        args = {}
        args["text"] = text
        args["path"] = path
        args["storage"] = storage
        args["parent"] = parent
        args["mode"] = mode
        return xcallback.open_url(
            url_with_params("outlinely://x-callback-url/insert", args)
        )


class OneWriter:
    """
    Actions for 1Writer.
    """

    def create(self, path=None, name=None, text=None) -> str:
        """ Create a new document. """

        args = {}
        args["path"] = path
        args["name"] = name
        args["text"] = text
        return xcallback.open_url(
            url_with_params("onewriter://x-callback-url/create", args)
        )

    def replace(self, path=None, text=None) -> str:
        """ Replace content of a document. """

        args = {}
        args["path"] = path
        args["text"] = text
        return xcallback.open_url(
            url_with_params("onewriter://x-callback-url/replace", args)
        )

    def replace_selection(self, text=None) -> str:
        """ Replace selected text in the current editing document. """

        args = {}
        args["text"] = text
        return xcallback.open_url(
            url_with_params("onewriter://x-callback-url/replace-selected", args)
        )

    def content(self, path=None, param=None) -> str:
        """ Return content of a document. """

        args = {}
        args["path"] = path
        args["param"] = param
        return xcallback.open_url(
            url_with_params("onewriter://x-callback-url/content", args)
        )

    def create_todo(self, path=None, name=None, text=None) -> str:
        """ Create a to-do list by separating lines of the text parameter. You can start a line with ”+” to indicate a completed todo. """

        args = {}
        args["path"] = path
        args["name"] = name
        args["text"] = text
        return xcallback.open_url(
            url_with_params("onewriter://x-callback-url/create-todo", args)
        )

    def open_document(self, path=None) -> str:
        """ Create a new document. """

        args = {}
        args["path"] = path
        return xcallback.open_url(
            url_with_params("onewriter://x-callback-url/open", args)
        )

    def append(self, path=None, text=None) -> str:
        """ Append to an existing document. """

        args = {}
        args["path"] = path
        args["text"] = text
        return xcallback.open_url(
            url_with_params("onewriter://x-callback-url/append", args)
        )

    def prepend(self, path=None, text=None) -> str:
        """ Prepend content to an existing document. """

        args = {}
        args["path"] = path
        args["text"] = text
        return xcallback.open_url(
            url_with_params("onewriter://x-callback-url/prepend", args)
        )


class Agenda:
    """
    Actions for Agenda.
    """

    def open_on_the_agenda(self) -> str:
        """ Open the On the Agenda overview. """

        args = {}
        return xcallback.open_url(
            url_with_params("agenda://x-callback-url/on-the-agenda", args)
        )

    def open_today(self) -> str:
        """ Open the Today overview. """

        args = {}
        return xcallback.open_url(
            url_with_params("agenda://x-callback-url/today", args)
        )

    def open_project(self, title=None, project_title=None, identifier=None) -> str:
        """ Open a project. Identified by title or identifier. """

        args = {}
        args["title"] = title
        args["project-title"] = project_title
        args["identifier"] = identifier
        return xcallback.open_url(
            url_with_params("agenda://x-callback-url/open-project", args)
        )

    def open_note(self, title=None, project_title=None, identifier=None) -> str:
        """ Open a note. Identified by title or identifier. """

        args = {}
        args["title"] = title
        args["project-title"] = project_title
        args["identifier"] = identifier
        return xcallback.open_url(
            url_with_params("agenda://x-callback-url/open-note", args)
        )

    def create_note(
        self,
        title,
        text,
        project_title=None,
        identifier=None,
        date=None,
        start_date=None,
        end_date=None,
        attachment=None,
        filename=None,
    ) -> str:
        """ Create a note. In the given project. (title or identifier) """

        args = {}
        args["title"] = title
        args["text"] = text
        args["project-title"] = project_title
        args["identifier"] = identifier
        args["date"] = date
        args["start-date"] = start_date
        args["end-date"] = end_date
        args["attachment"] = attachment
        args["filename"] = filename
        return xcallback.open_url(
            url_with_params("agenda://x-callback-url/create-note", args)
        )

    def append_to_note(
        self,
        text,
        on_the_agenda,
        title=None,
        project_title=None,
        identifier=None,
        date=None,
        start_date=None,
        end_date=None,
        attachment=None,
        filename=None,
    ) -> str:
        """ Append text or an attachment to a note, or change the title or date """

        args = {}
        args["text"] = text
        args["on-the-agenda"] = on_the_agenda
        args["title"] = title
        args["project-title"] = project_title
        args["identifier"] = identifier
        args["date"] = date
        args["start-date"] = start_date
        args["end-date"] = end_date
        args["attachment"] = attachment
        args["filename"] = filename
        return xcallback.open_url(
            url_with_params("agenda://x-callback-url/append-to-note", args)
        )


class Scriptable:
    """
    Actions for Scriptable.
    """

    def open_scriptable(self):
        """ Opens Scriptable. """

        args = {}
        webbrowser.open(url_with_params("scriptable://", args))

    def add_script(self):
        """ Add a new script. """

        args = {}
        webbrowser.open(url_with_params("scriptable:///add", args))

    def open_script(self, scriptName, openSettings=None):
        """ Add a new script. """

        args = {}
        args["scriptName"] = scriptName
        args["openSettings"] = openSettings
        webbrowser.open(url_with_params("scriptable:///open", args))

    def run_script(self, scriptName):
        """ Run a script. """

        args = {}
        args["scriptName"] = scriptName
        webbrowser.open(url_with_params("scriptable:///run", args))


class Trello:
    """
    Actions for Trello.
    """

    def show_board(self, id=None, shortlink=None) -> str:
        """ Links to a board. """

        args = {}
        args["id"] = id
        args["shortlink"] = shortlink
        return xcallback.open_url(
            url_with_params("trello://x-callback-url/showBoard", args)
        )

    def show_cards(self, id=None, shortlink=None) -> str:
        """ Links to a card. """

        args = {}
        args["id"] = id
        args["shortlink"] = shortlink
        return xcallback.open_url(
            url_with_params("trello://x-callback-url/showCard", args)
        )

    def create_board(self, name=None, organization=None, permission=None) -> str:
        """ Creates a new board. """

        args = {}
        args["name"] = name
        args["organization"] = organization
        args["permission"] = permission
        return xcallback.open_url(
            url_with_params("trello://x-callback-url/createBoard", args)
        )

    def create_card(
        self,
        id=None,
        shortlink=None,
        name=None,
        description=None,
        list_id=None,
        use_pasteboard=None,
    ) -> str:
        """ Creates a new card in a specified board. """

        args = {}
        args["id"] = id
        args["shortlink"] = shortlink
        args["name"] = name
        args["description"] = description
        args["list-id"] = list_id
        args["use-pasteboard"] = use_pasteboard
        return xcallback.open_url(
            url_with_params("trello://x-callback-url/createCard", args)
        )


class Notes:
    """
    Actions for Notes.
    """

    def show_note(self, identifier):
        """ A direct link to a note. To get the identifier see the documentation url above. """

        args = {}
        args["identifier"] = identifier
        webbrowser.open(url_with_params("mobilenotes://showNote", args))


class Things3:
    """
    Actions for Things 3.
    """

    def add(
        self,
        title=None,
        titles=None,
        notes=None,
        when=None,
        deadline=None,
        tags=None,
        checklist_items=None,
        list_id=None,
        list=None,
        heading=None,
        completed=None,
        canceled=None,
        show_quick_entry=None,
        reveal=None,
        creation_date=None,
        completion_date=None,
    ):
        """ Add a to-do. """

        args = {}
        args["title"] = title
        args["titles"] = titles
        args["notes"] = notes
        args["when"] = when
        args["deadline"] = deadline
        args["tags"] = tags
        args["checklist-items"] = checklist_items
        args["list-id"] = list_id
        args["list"] = list
        args["heading"] = heading
        args["completed"] = completed
        args["canceled"] = canceled
        args["show-quick-entry"] = show_quick_entry
        args["reveal"] = reveal
        args["creation-date"] = creation_date
        args["completion-date"] = completion_date
        webbrowser.open(url_with_params("things://add", args))

    def add_project(
        self,
        title=None,
        notes=None,
        when=None,
        deadline=None,
        tags=None,
        area_id=None,
        area=None,
        to_dos=None,
        completed=None,
        canceled=None,
        reveal=None,
        creation_date=None,
        completion_date=None,
    ):
        """ Add a project. """

        args = {}
        args["title"] = title
        args["notes"] = notes
        args["when"] = when
        args["deadline"] = deadline
        args["tags"] = tags
        args["area-id"] = area_id
        args["area"] = area
        args["to-dos"] = to_dos
        args["completed"] = completed
        args["canceled"] = canceled
        args["reveal"] = reveal
        args["creation-date"] = creation_date
        args["completion-date"] = completion_date
        webbrowser.open(url_with_params("things://add-project", args))

    def update(
        self,
        auth_token,
        id,
        title=None,
        notes=None,
        prepend_notes=None,
        append_notes=None,
        when=None,
        deadline=None,
        tags=None,
        add_tags=None,
        checklist_items=None,
        prepend_checklist_items=None,
        append_checklist_items=None,
        list_id=None,
        list=None,
        heading=None,
        completed=None,
        canceled=None,
        reveal=None,
        duplicate=None,
        creation_date=None,
        completion_date=None,
    ):
        """ Update an existing to-do. """

        args = {}
        args["auth-token"] = auth_token
        args["id"] = id
        args["title"] = title
        args["notes"] = notes
        args["prepend-notes"] = prepend_notes
        args["append-notes"] = append_notes
        args["when"] = when
        args["deadline"] = deadline
        args["tags"] = tags
        args["add-tags"] = add_tags
        args["checklist-items"] = checklist_items
        args["prepend-checklist-items"] = prepend_checklist_items
        args["append-checklist-items"] = append_checklist_items
        args["list-id"] = list_id
        args["list"] = list
        args["heading"] = heading
        args["completed"] = completed
        args["canceled"] = canceled
        args["reveal"] = reveal
        args["duplicate"] = duplicate
        args["creation-date"] = creation_date
        args["completion-date"] = completion_date
        webbrowser.open(url_with_params("things://update", args))

    def update_project(
        self,
        auth_token,
        id,
        title=None,
        notes=None,
        prepend_notes=None,
        append_notes=None,
        when=None,
        deadline=None,
        tags=None,
        add_tags=None,
        area_id=None,
        area=None,
        completed=None,
        canceled=None,
        reveal=None,
        duplicate=None,
        creation_date=None,
        completion_date=None,
    ):
        """ Update an existing project. """

        args = {}
        args["auth-token"] = auth_token
        args["id"] = id
        args["title"] = title
        args["notes"] = notes
        args["prepend-notes"] = prepend_notes
        args["append-notes"] = append_notes
        args["when"] = when
        args["deadline"] = deadline
        args["tags"] = tags
        args["add-tags"] = add_tags
        args["area-id"] = area_id
        args["area"] = area
        args["completed"] = completed
        args["canceled"] = canceled
        args["reveal"] = reveal
        args["duplicate"] = duplicate
        args["creation-date"] = creation_date
        args["completion-date"] = completion_date
        webbrowser.open(url_with_params("things://update-project", args))

    def show(self, id=None, query=None, filter=None):
        """ Navigate to and show an area, project, tag or to-do, or one of the built-in lists, optionally filtering by one or more tags. """

        args = {}
        args["id"] = id
        args["query"] = query
        args["filter"] = filter
        webbrowser.open(url_with_params("things://show", args))

    def search(self, query=None):
        """ Invoke and show the search screen. """

        args = {}
        args["query"] = query
        webbrowser.open(url_with_params("things://search", args))

    def version(self):
        """ The version of the Things app and URL scheme. """

        args = {}
        webbrowser.open(url_with_params("things://version", args))

    def json(self, auth_token=None, data=None, reveal=None):
        """ Things also has an advanced, JSON-based add command that allows more control over the projects and to-dos imported into Things. This command is intended to be used by app developers or other people familiar with scripting or programming. """

        args = {}
        args["auth-token"] = auth_token
        args["data"] = data
        args["reveal"] = reveal
        webbrowser.open(url_with_params("things://json", args))


class Copied:
    """
    Actions for Copied.
    """

    def show_clipboard(self):
        """ Show the clipboard. """

        args = {}
        webbrowser.open(url_with_params("copied://clipboard", args))

    def open_list(self):
        """ Open list with the name ”listName”. """

        args = {}
        webbrowser.open(url_with_params("copied://list/{listName}", args))

    def find_clipping(self, q):
        """ Search the content with a query. """

        args = {}
        args["q"] = q
        webbrowser.open(url_with_params("copied://search", args))

    def new_clipping(self, title=None, text=None, url=None, list=None) -> str:
        """ Add a new clipping to Copied. All parameters are option, if neither ”title” nor ”url” are given the content of the clipboard will be used. """

        args = {}
        args["title"] = title
        args["text"] = text
        args["url"] = url
        args["list"] = list
        return xcallback.open_url(url_with_params("copied://x-callback-url/save", args))

    def copy_clipping(self, index, list=None) -> str:
        """ Copy the clipping at the given index. """

        args = {}
        args["index"] = index
        args["list"] = list
        return xcallback.open_url(url_with_params("copied://x-callback-url/copy", args))


class Bitly:
    """
    Actions for Bitly.
    """

    def shorten(self, url) -> str:
        """ Create a shortened link. The user will be prompted to add the new link to her list of links. If she chooses not to, the link will be returned as a "url" parameter on the x-success callback. """

        args = {}
        args["url"] = url
        return xcallback.open_url(
            url_with_params("bitly://x-callback-url/shorten", args)
        )


class Due:
    """
    Actions for Due.
    """

    def add(
        self,
        title=None,
        duedate=None,
        secslater=None,
        minslater=None,
        hourslater=None,
        timezone=None,
        recurunit=None,
        recurfreq=None,
        recurfromdate=None,
        recurbyday=None,
        recurbysetpos=None,
    ) -> str:
        """ Launches Due on the iOS device with the add reminder view prefilled using information provided in the parameters described below. """

        args = {}
        args["title"] = title
        args["duedate"] = duedate
        args["secslater"] = secslater
        args["minslater"] = minslater
        args["hourslater"] = hourslater
        args["timezone"] = timezone
        args["recurunit"] = recurunit
        args["recurfreq"] = recurfreq
        args["recurfromdate"] = recurfromdate
        args["recurbyday"] = recurbyday
        args["recurbysetpos"] = recurbysetpos
        return xcallback.open_url(url_with_params("due://x-callback-url/add", args))

    def search(self, query=None, section=None) -> str:
        """ Launches Due on the iOS device and searches for a query string in the specified section. """

        args = {}
        args["query"] = query
        args["section"] = section
        return xcallback.open_url(url_with_params("due://x-callback-url/search", args))


class Coda:
    """
    Actions for Coda.
    """

    def new(self, name, path=None, text=None) -> str:
        """ Creates a new file. If one exists, a file with a unique name will be created. """

        args = {}
        args["name"] = name
        args["path"] = path
        args["text"] = text
        return xcallback.open_url(url_with_params("coda://x-callback-url/new", args))

    def append(self, name=None, path=None, text=None) -> str:
        """ Append text to a file, creating it if necessary. """

        args = {}
        args["name"] = name
        args["path"] = path
        args["text"] = text
        return xcallback.open_url(url_with_params("coda://x-callback-url/append", args))

    def replace(self, name=None, path=None, text=None) -> str:
        """ Replaces the contents of a file, creating it if necessary. """

        args = {}
        args["name"] = name
        args["path"] = path
        args["text"] = text
        return xcallback.open_url(
            url_with_params("coda://x-callback-url/replace", args)
        )


class Textastic:
    """
    Actions for Textastic.
    """

    def new_file(
        self, location=None, path=None, name=None, text=None, snippet=None
    ) -> str:
        """ Create a new file in the local file system or in iCloud. If neither the text parameter nor the snippet parameter is specified, the text to append will come from the clipboard. """

        args = {}
        args["location"] = location
        args["path"] = path
        args["name"] = name
        args["text"] = text
        args["snippet"] = snippet
        return xcallback.open_url(
            url_with_params("textastic://x-callback-url/new", args)
        )

    def open_file(self, location=None, path=None, name=None) -> str:
        """ Open an existing file in the local file system or in iCloud. If the file doesn’t exist, calls the url from the x-error parameter. """

        args = {}
        args["location"] = location
        args["path"] = path
        args["name"] = name
        return xcallback.open_url(
            url_with_params("textastic://x-callback-url/open", args)
        )

    def append(
        self, location=None, path=None, name=None, text=None, snippet=None
    ) -> str:
        """ Open an existing file or create a new file and append text. If neither the text parameter nor the snippet parameter is specified, the text to append will come from the clipboard. """

        args = {}
        args["location"] = location
        args["path"] = path
        args["name"] = name
        args["text"] = text
        args["snippet"] = snippet
        return xcallback.open_url(
            url_with_params("textastic://x-callback-url/append", args)
        )

    def replace(
        self, location=None, path=None, name=None, text=None, snippet=None
    ) -> str:
        """ Open an existing file or create a new file and replace its contents with the specified text. If neither the text parameter nor the snippet parameter is specified, the text to append will come from the clipboard. """

        args = {}
        args["location"] = location
        args["path"] = path
        args["name"] = name
        args["text"] = text
        args["snippet"] = snippet
        return xcallback.open_url(
            url_with_params("textastic://x-callback-url/replace", args)
        )


class Prizmo:
    """
    Actions for Prizmo Go.
    """

    def capture_text(
        self, language=None, destination=None, pasteboardName=None, cropMode=None
    ) -> str:
        """ Start Prizmo to take a picture and perform English OCR on it. The following options are supported: """

        args = {}
        args["language"] = language
        args["destination"] = destination
        args["pasteboardName"] = pasteboardName
        args["cropMode"] = cropMode
        return xcallback.open_url(
            url_with_params("prizmo://x-callback-url/captureText", args)
        )

    def read_text(self, text, voice=None, language=None) -> str:
        """ Will read the provided text with the Ryan voice in Prizmo Voice Reader. """

        args = {}
        args["text"] = text
        args["voice"] = voice
        args["language"] = language
        return xcallback.open_url(
            url_with_params("prizmo://x-callback-url/readText", args)
        )


class IcabMobile:
    """
    Actions for iCab Mobile.
    """

    def add_bookmark(self, url, title=None) -> str:
        """ Adds a bookmark with the given URL and title to the Bookmarks of iCab Mobile """

        args = {}
        args["url"] = url
        args["title"] = title
        return xcallback.open_url(
            url_with_params("x-icabmobile://x-callback-url/addBookmark", args)
        )

    def add_filter(self, url, type=None) -> str:
        """ Creates a new filter. Without the type parameter, iCab defaults to “block” """

        args = {}
        args["url"] = url
        args["type"] = type
        return xcallback.open_url(
            url_with_params("x-icabmobile://x-callback-url/addFilter", args)
        )

    def add_search_engine(self, url, title=None) -> str:
        """ Adds a new search engine to the list of search engines. """

        args = {}
        args["url"] = url
        args["title"] = title
        return xcallback.open_url(
            url_with_params("x-icabmobile://x-callback-url/addSearchEngine", args)
        )

    def add_reading_list(self, url, title=None) -> str:
        """ Adds the page with the given URL and title to the Reading list """

        args = {}
        args["url"] = url
        args["title"] = title
        return xcallback.open_url(
            url_with_params("x-icabmobile://x-callback-url/addReadingList", args)
        )

    def search(self, searchTerm=None) -> str:
        """ Launches iCab and opens the search window, so the user can directly start entering a search term, if the search term is given, the search is started immediately. """

        args = {}
        args["searchTerm"] = searchTerm
        return xcallback.open_url(
            url_with_params("x-icabmobile://x-callback-url/search", args)
        )

    def fullscreen(self) -> str:
        """ Launches iCab in fullscreen mode. """

        args = {}
        return xcallback.open_url(
            url_with_params("x-icabmobile://x-callback-url/fullscreen", args)
        )

    def normal_mode(self) -> str:
        """ Launches iCab in normal mode. """

        args = {}
        return xcallback.open_url(
            url_with_params("x-icabmobile://x-callback-url/normalmode", args)
        )

    def open(self, url, destination=None, fullscreen=None) -> str:
        """ Opens the page in the given destination and enters the fullscreen mode when requested. The URL “quickstarter:” can be used to open the Quickstarter page. """

        args = {}
        args["url"] = url
        args["destination"] = destination
        args["fullscreen"] = fullscreen
        return xcallback.open_url(
            url_with_params("x-icabmobile://x-callback-url/open", args)
        )

    def download(self, url, filename=None, referrer=None) -> str:
        """ Starts the download of the file at URL and uses the filename to save it in the download manager. """

        args = {}
        args["url"] = url
        args["filename"] = filename
        args["referrer"] = referrer
        return xcallback.open_url(
            url_with_params("x-icabmobile://x-callback-url/download", args)
        )


class Fantastical2:
    """
    Actions for Fantastical 2.
    """

    def parse(
        self,
        sentence=None,
        notes=None,
        add=None,
        reminder=None,
        due=None,
        title=None,
        location=None,
        url=None,
        start=None,
        end=None,
        allDay=None,
    ) -> str:
        """ Begin creating a new event with the given sentence. """

        args = {}
        args["sentence"] = sentence
        args["notes"] = notes
        args["add"] = add
        args["reminder"] = reminder
        args["due"] = due
        args["title"] = title
        args["location"] = location
        args["url"] = url
        args["start"] = start
        args["end"] = end
        args["allDay"] = allDay
        return xcallback.open_url(
            url_with_params("fantastical2://x-callback-url/parse", args)
        )

    def show(self, date=None) -> str:
        """ Jumps to the specified date. """

        args = {}
        args["date"] = date
        return xcallback.open_url(
            url_with_params("fantastical2://x-callback-url/show", args)
        )


class Overcast:
    """
    Actions for Overcast.
    """

    def add_url(self, url=None) -> str:
        """ Subscribe to a new show under the given URL """

        args = {}
        args["url"] = url
        return xcallback.open_url(
            url_with_params("overcast://x-callback-url/add", args)
        )


class CodeHub:
    """
    Actions for CodeHub.
    """

    def create_new_gist(self, description=None, public=None, fileN=None) -> str:
        """ Create a new gist on github.com. """

        args = {}
        args["description"] = description
        args["public"] = public
        args["fileN"] = fileN
        return xcallback.open_url(
            url_with_params("codehub://x-callback-url/gist/create", args)
        )


class Vlc:
    """
    Actions for VLC.
    """

    def stream(self, url=None) -> str:
        """ Plays the stream provided by the ”url” parameter """

        args = {}
        args["url"] = url
        return xcallback.open_url(
            url_with_params("vlc-x-callback://x-callback-url/stream", args)
        )

    def download(self, url=None, filename=None) -> str:
        """ Download the file provided by the ”url” parameter """

        args = {}
        args["url"] = url
        args["filename"] = filename
        return xcallback.open_url(
            url_with_params("vlc-x-callback://x-callback-url/download", args)
        )


class TextkraftPocket:
    """
    Actions for Textkraft.
    """

    def create(self, text=None) -> str:
        """ Creates a new document. """

        args = {}
        args["text"] = text
        return xcallback.open_url(
            url_with_params("textkraftpocket://x-callback-url/create", args)
        )

    def append(self, text=None) -> str:
        """ Appends text to the current (frontmost) document, if this is an editable text document. """

        args = {}
        args["text"] = text
        return xcallback.open_url(
            url_with_params("textkraftpocket://x-callback-url/append", args)
        )


class Beorg:
    """
    Actions for beorg.
    """

    def capture(
        self,
        title=None,
        notes=None,
        scheduled=None,
        deadline=None,
        file=None,
        template=None,
        edit=None,
    ) -> str:
        """ Add a new item to a file """

        args = {}
        args["title"] = title
        args["notes"] = notes
        args["scheduled"] = scheduled
        args["deadline"] = deadline
        args["file"] = file
        args["template"] = template
        args["edit"] = edit
        return xcallback.open_url(
            url_with_params("beorg://x-callback-url/capture", args)
        )

    def view_agenda(self) -> str:
        """ Open the app to the agenda view """

        args = {}
        return xcallback.open_url(
            url_with_params("beorg://x-callback-url/agenda", args)
        )

    def view_a_file(self, file) -> str:
        """ Open the provided file for viewing """

        args = {}
        args["file"] = file
        return xcallback.open_url(url_with_params("beorg://x-callback-url/file", args))


class Opener:
    """
    Actions for Opener.
    """

    def show_options(self, url, allow_auto_open=None) -> str:
        """ Show the available options to open a given URL. """

        args = {}
        args["url"] = url
        args["allow-auto-open"] = allow_auto_open
        return xcallback.open_url(
            url_with_params("opener://x-callback-url/show-options", args)
        )

    def show_store_product_details(self, id) -> str:
        """ Shows the details of an iTunes product within Opener (or Opener's action extension if open) in an ”SKStoreProductViewController” or an iOS store app. """

        args = {}
        args["id"] = id
        return xcallback.open_url(
            url_with_params("opener://x-callback-url/show-store-product-details", args)
        )


class Awair:
    """
    Actions for Awair.
    """

    def list(self):
        """ Opens the Device List view """

        args = {}
        webbrowser.open(url_with_params("awair://list", args))

    def score(self):
        """ Opens the Awair Score tab """

        args = {}
        webbrowser.open(url_with_params("awair://score", args))

    def tips(self):
        """ Opens the Tips tab """

        args = {}
        webbrowser.open(url_with_params("awair://tips", args))

    def trend(self, deviceType, deiviceId, component, timestamp):
        """ Opens the Trend tab """

        args = {}
        args["deviceType"] = deviceType
        args["deiviceId"] = deiviceId
        args["component"] = component
        args["timestamp"] = timestamp
        webbrowser.open(url_with_params("awair://trend", args))

    def awairplus(self):
        """ Opens the Awair+ tab """

        args = {}
        webbrowser.open(url_with_params("awair://awairplus", args))

    def notifications(self):
        """ Opens the Inbox tab """

        args = {}
        webbrowser.open(url_with_params("awair://notifications", args))


class DayOne:
    """
    Actions for Day One.
    """

    def create_entry(self, entry, tags=None, journal=None, imageClipboard=None):
        """  """

        args = {}
        args["entry"] = entry
        args["tags"] = tags
        args["journal"] = journal
        args["imageClipboard"] = imageClipboard
        webbrowser.open(url_with_params("dayone://post", args))

    def edit_entry(self, entryId):
        """  """

        args = {}
        args["entryId"] = entryId
        webbrowser.open(url_with_params("dayone://edit", args))

    def open_day_one(self):
        """  """

        args = {}
        webbrowser.open(url_with_params("dayone://", args))

    def open_actifity_feed(self):
        """  """

        args = {}
        webbrowser.open(url_with_params("dayone://activity", args))

    def open_timeline(self):
        """  """

        args = {}
        webbrowser.open(url_with_params("dayone://entries", args))

    def open_calendar(self):
        """  """

        args = {}
        webbrowser.open(url_with_params("dayone://calendar", args))

    def open_starred_entries(self):
        """  """

        args = {}
        webbrowser.open(url_with_params("dayone://astarred", args))

    def open_preferences(self):
        """  """

        args = {}
        webbrowser.open(url_with_params("dayone://preferences", args))


class Drafts5:
    """
    Actions for Drafts 5.
    """

    def create(self, text, tag=None, action=None, allowEmpty=None) -> str:
        """ Create a new draft with the content passed in the “text” argument. """

        args = {}
        args["text"] = text
        args["tag"] = tag
        args["action"] = action
        args["allowEmpty"] = allowEmpty
        return xcallback.open_url(
            url_with_params("drafts5://x-callback-url/create", args)
        )

    def open(self, uuid, action=None, allowEmpty=None) -> str:
        """ Open an existing draft based on the UUID argument. """

        args = {}
        args["uuid"] = uuid
        args["action"] = action
        args["allowEmpty"] = allowEmpty
        return xcallback.open_url(
            url_with_params("drafts5://x-callback-url/open", args)
        )

    def get(self, uuid, retParam=None) -> str:
        """ Return the current content of the draft specified by the UUID argument as an argument to the x-success URL provided. """

        args = {}
        args["uuid"] = uuid
        args["retParam"] = retParam
        return xcallback.open_url(url_with_params("drafts5://x-callback-url/get", args))

    def prepend(self, uuid, text, action=None, allowEmpty=None, tag=None) -> str:
        """ Prepend the passed text to the beginning of a draft identified by the UUID argument. """

        args = {}
        args["uuid"] = uuid
        args["text"] = text
        args["action"] = action
        args["allowEmpty"] = allowEmpty
        args["tag"] = tag
        return xcallback.open_url(
            url_with_params("drafts5://x-callback-url/prepend", args)
        )

    def append(self, uuid, text, action=None, allowEmpty=None, tag=None) -> str:
        """ Append the passed text to the end of a draft identified by the UUID argument. """

        args = {}
        args["uuid"] = uuid
        args["text"] = text
        args["action"] = action
        args["allowEmpty"] = allowEmpty
        args["tag"] = tag
        return xcallback.open_url(
            url_with_params("drafts5://x-callback-url/prepend", args)
        )

    def repace_range(self, uuid, text, start, length) -> str:
        """ Replace content in an existing draft, based on a range. """

        args = {}
        args["uuid"] = uuid
        args["text"] = text
        args["start"] = start
        args["length"] = length
        return xcallback.open_url(
            url_with_params("drafts5://x-callback-url/replaceRange", args)
        )

    def search(self, query=None, tag=None) -> str:
        """ Open drafts directly to the draft search field. """

        args = {}
        args["query"] = query
        args["tag"] = tag
        return xcallback.open_url(
            url_with_params("drafts5://x-callback-url/search", args)
        )

    def workspace(self, name=None) -> str:
        """ Open drafts directly the draft list with a named workspace selected. """

        args = {}
        args["name"] = name
        return xcallback.open_url(
            url_with_params("drafts5://x-callback-url/workspace", args)
        )

    def run_action(self, text, action=None, allowEmpty=None) -> str:
        """ Run a drafts action on the passed text without saving that text to a draft. """

        args = {}
        args["text"] = text
        args["action"] = action
        args["allowEmpty"] = allowEmpty
        return xcallback.open_url(
            url_with_params("drafts5://x-callback-url/runAction", args)
        )

    def dictate(self, locale=None, retParam=None) -> str:
        """ Open Drafts dictation interface. Pass the resulting dictated text to the x-success URL instead of saving it in Drafts. """

        args = {}
        args["locale"] = locale
        args["retParam"] = retParam
        return xcallback.open_url(
            url_with_params("drafts5://x-callback-url/dictate", args)
        )

    def arrange(self, text, retParam=None) -> str:
        """ Open Drafts arrange interface. Pass the resulting arranged text to the x-success URL instead of saving it in Drafts. """

        args = {}
        args["text"] = text
        args["retParam"] = retParam
        return xcallback.open_url(
            url_with_params("drafts5://x-callback-url/arrange", args)
        )


class Bear:
    """
    Actions for Bear.
    """

    def open_note(self, id=None, title=None, exclude_trashed=None) -> str:
        """ Open a note identified by its title or id and return its content. """

        args = {}
        args["id"] = id
        args["title"] = title
        args["exclude_trashed"] = exclude_trashed
        return xcallback.open_url(
            url_with_params("bear://x-callback-url/open-note", args)
        )

    def create_note(
        self,
        title=None,
        text=None,
        tags=None,
        pin=None,
        file=None,
        filename=None,
        open_note=None,
    ) -> str:
        """ Create a new note and return its unique identifier. Empty notes are not allowed. """

        args = {}
        args["title"] = title
        args["text"] = text
        args["tags"] = tags
        args["pin"] = pin
        args["file"] = file
        args["filename"] = filename
        args["open_note"] = open_note
        return xcallback.open_url(url_with_params("bear://x-callback-url/create", args))

    def add_text(
        self,
        id=None,
        title=None,
        text=None,
        mode=None,
        exclude_trashed=None,
        open_note=None,
    ) -> str:
        """ Append or prepent text to a note identified by its title or id. """

        args = {}
        args["id"] = id
        args["title"] = title
        args["text"] = text
        args["mode"] = mode
        args["exclude_trashed"] = exclude_trashed
        args["open_note"] = open_note
        return xcallback.open_url(
            url_with_params("bear://x-callback-url/add-text", args)
        )

    def add_file(
        self, id=None, title=None, file=None, filename=None, mode=None, open_note=None
    ) -> str:
        """ Append or prepend a file to a note identified by its title or id. """

        args = {}
        args["id"] = id
        args["title"] = title
        args["file"] = file
        args["filename"] = filename
        args["mode"] = mode
        args["open_note"] = open_note
        return xcallback.open_url(
            url_with_params("bear://x-callback-url/add-file", args)
        )

    def open_tag(self, name=None) -> str:
        """ Show all the notes which have a selected tag in bear. """

        args = {}
        args["name"] = name
        return xcallback.open_url(
            url_with_params("bear://x-callback-url/open-tag", args)
        )

    def rename_tag(self, name=None, new_name=None) -> str:
        """ Rename an existing tag. """

        args = {}
        args["name"] = name
        args["new_name"] = new_name
        return xcallback.open_url(
            url_with_params("bear://x-callback-url/rename-tag", args)
        )

    def delete_tag(self, name=None) -> str:
        """ Delete an existing tag. """

        args = {}
        args["name"] = name
        return xcallback.open_url(
            url_with_params("bear://x-callback-url/delete-tag", args)
        )

    def trash(self, id=None) -> str:
        """ Move a note to bear trash. """

        args = {}
        args["id"] = id
        return xcallback.open_url(url_with_params("bear://x-callback-url/trash", args))

    def search(self, term=None, tag=None) -> str:
        """ Show search results in Bear for all notes or for a specific tag. """

        args = {}
        args["term"] = term
        args["tag"] = tag
        return xcallback.open_url(url_with_params("bear://x-callback-url/search", args))

    def grab_url(self, url=None, images=None, tags=None, pin=None) -> str:
        """ Create a new note with the content of a web page. """

        args = {}
        args["url"] = url
        args["images"] = images
        args["tags"] = tags
        args["pin"] = pin
        return xcallback.open_url(
            url_with_params("bear://x-callback-url/grab-url", args)
        )

    def change_theme(self, theme=None) -> str:
        """ Change the selected Bear theme. Some themes may require a Bear Pro subscription. """

        args = {}
        args["theme"] = theme
        return xcallback.open_url(
            url_with_params("bear://x-callback-url/change-theme", args)
        )

    def change_font(self, font=None) -> str:
        """ Change the selected Bear Font. """

        args = {}
        args["font"] = font
        return xcallback.open_url(
            url_with_params("bear://x-callback-url/change-font", args)
        )
