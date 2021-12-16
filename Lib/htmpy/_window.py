import sys

if "sphinx" in sys.modules:

    class JSObject:
        pass

    window = JSObject()
    """
    A bridge of the JavaScript ``window`` object that can be accessed from scripts running in an HTML web page.
    """

else:

    class window:
        class document:
            class location:
                href = None
                protocol = None
                host = None
                hostname = None
                port = None
                pathname = None
                search = None
                hash = None
                origin = None
                ancestorOrigins = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                assign = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                reload = None
                replace = None
                toLocaleString = None
                toString = None
                valueOf = None

            class implementation:
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                createDocument = None
                createDocumentType = None
                createHTMLDocument = None
                hasFeature = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            URL = None
            documentURI = None
            compatMode = None
            characterSet = None
            charset = None
            inputEncoding = None
            contentType = None
            doctype = None

            class documentElement:
                version = None
                manifest = None
                title = None
                lang = None
                translate = None
                dir = None
                hidden = None
                accessKey = None
                accessKeyLabel = None
                draggable = None
                spellcheck = None
                autocapitalize = None
                innerText = None
                outerText = None
                autocorrect = None
                webkitdropzone = None
                style = None
                oncopy = None
                oncut = None
                onpaste = None
                onbeforecopy = None
                onbeforecut = None
                onbeforeinput = None
                onbeforepaste = None
                contentEditable = None
                enterKeyHint = None
                isContentEditable = None
                inputMode = None
                onabort = None
                onblur = None
                oncanplay = None
                oncanplaythrough = None
                onchange = None
                onclick = None
                onclose = None
                oncontextmenu = None
                oncuechange = None
                ondblclick = None
                ondrag = None
                ondragend = None
                ondragenter = None
                ondragleave = None
                ondragover = None
                ondragstart = None
                ondrop = None
                ondurationchange = None
                onemptied = None
                onended = None
                onerror = None
                onfocus = None
                onformdata = None
                oninput = None
                oninvalid = None
                onkeydown = None
                onkeypress = None
                onkeyup = None
                onload = None
                onloadeddata = None
                onloadedmetadata = None
                onloadstart = None
                onmousedown = None
                onmouseenter = None
                onmouseleave = None
                onmousemove = None
                onmouseout = None
                onmouseover = None
                onmouseup = None
                onpause = None
                onplay = None
                onplaying = None
                onprogress = None
                onratechange = None
                onreset = None
                onresize = None
                onscroll = None
                onseeked = None
                onseeking = None
                onselect = None
                onslotchange = None
                onstalled = None
                onsubmit = None
                onsuspend = None
                ontimeupdate = None
                ontoggle = None
                onvolumechange = None
                onwaiting = None
                onwebkitanimationend = None
                onwebkitanimationiteration = None
                onwebkitanimationstart = None
                onwebkittransitionend = None
                onwheel = None
                onmousewheel = None
                onsearch = None
                ontouchcancel = None
                ontouchend = None
                ontouchmove = None
                ontouchstart = None
                ontouchforcechange = None
                onwebkitmouseforcechanged = None
                onwebkitmouseforcedown = None
                onwebkitmouseforcewillbegin = None
                onwebkitmouseforceup = None
                onanimationstart = None
                onanimationiteration = None
                onanimationend = None
                onanimationcancel = None
                ontransitionrun = None
                ontransitionstart = None
                ontransitionend = None
                ontransitioncancel = None
                ongotpointercapture = None
                onlostpointercapture = None
                onpointerdown = None
                onpointermove = None
                onpointerup = None
                onpointercancel = None
                onpointerover = None
                onpointerout = None
                onpointerenter = None
                onpointerleave = None
                onselectstart = None
                onselectionchange = None
                offsetParent = None
                offsetTop = None
                offsetLeft = None
                offsetWidth = None
                offsetHeight = None
                dataset = None
                tabIndex = None
                namespaceURI = None
                prefix = None
                localName = None
                tagName = None
                id = None
                className = None
                classList = None
                slot = None
                part = None
                attributes = None
                shadowRoot = None
                onfocusin = None
                onfocusout = None
                ongesturechange = None
                ongestureend = None
                ongesturestart = None
                onbeforeload = None
                onwebkitneedkey = None
                onwebkitpresentationmodechanged = None
                onwebkitcurrentplaybacktargetiswirelesschanged = None
                onwebkitplaybacktargetavailabilitychanged = None
                role = None
                ariaAtomic = None
                ariaAutoComplete = None
                ariaBusy = None
                ariaChecked = None
                ariaColCount = None
                ariaColIndex = None
                ariaColSpan = None
                ariaCurrent = None
                ariaDisabled = None
                ariaExpanded = None
                ariaHasPopup = None
                ariaHidden = None
                ariaInvalid = None
                ariaKeyShortcuts = None
                ariaLabel = None
                ariaLevel = None
                ariaLive = None
                ariaModal = None
                ariaMultiLine = None
                ariaMultiSelectable = None
                ariaOrientation = None
                ariaPlaceholder = None
                ariaPosInSet = None
                ariaPressed = None
                ariaReadOnly = None
                ariaRelevant = None
                ariaRequired = None
                ariaRoleDescription = None
                ariaRowCount = None
                ariaRowIndex = None
                ariaRowSpan = None
                ariaSelected = None
                ariaSetSize = None
                ariaSort = None
                ariaValueMax = None
                ariaValueMin = None
                ariaValueNow = None
                ariaValueText = None
                scrollTop = None
                scrollLeft = None
                scrollWidth = None
                scrollHeight = None
                clientTop = None
                clientLeft = None
                clientWidth = None
                clientHeight = None
                outerHTML = None
                innerHTML = None
                previousElementSibling = None
                nextElementSibling = None
                children = None
                firstElementChild = None
                lastElementChild = None
                childElementCount = None
                assignedSlot = None
                nodeType = None
                nodeName = None
                baseURI = None
                isConnected = None
                ownerDocument = None
                parentNode = None
                parentElement = None
                childNodes = None
                firstChild = None
                lastChild = None
                previousSibling = None
                nextSibling = None
                nodeValue = None
                textContent = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                addEventListener = None
                after = None
                animate = None
                append = None
                appendChild = None
                attachShadow = None
                before = None
                blur = None
                click = None
                cloneNode = None
                closest = None
                compareDocumentPosition = None
                contains = None
                dispatchEvent = None
                focus = None
                getAnimations = None
                getAttribute = None
                getAttributeNS = None
                getAttributeNames = None
                getAttributeNode = None
                getAttributeNodeNS = None
                getBoundingClientRect = None
                getClientRects = None
                getElementsByClassName = None
                getElementsByTagName = None
                getElementsByTagNameNS = None
                getRootNode = None
                hasAttribute = None
                hasAttributeNS = None
                hasAttributes = None
                hasChildNodes = None
                hasOwnProperty = None
                hasPointerCapture = None
                insertAdjacentElement = None
                insertAdjacentHTML = None
                insertAdjacentText = None
                insertBefore = None
                isDefaultNamespace = None
                isEqualNode = None
                isPrototypeOf = None
                isSameNode = None
                lookupNamespaceURI = None
                lookupPrefix = None
                matches = None
                normalize = None
                prepend = None
                propertyIsEnumerable = None
                querySelector = None
                querySelectorAll = None
                releasePointerCapture = None
                remove = None
                removeAttribute = None
                removeAttributeNS = None
                removeAttributeNode = None
                removeChild = None
                removeEventListener = None
                replaceChild = None
                replaceChildren = None
                replaceWith = None
                scroll = None
                scrollBy = None
                scrollIntoView = None
                scrollIntoViewIfNeeded = None
                scrollTo = None
                setAttribute = None
                setAttributeNS = None
                setAttributeNode = None
                setAttributeNodeNS = None
                setPointerCapture = None
                toLocaleString = None
                toString = None
                toggleAttribute = None
                valueOf = None
                webkitMatchesSelector = None

            xmlEncoding = None

            xmlVersion = None

            xmlStandalone = None
            pictureInPictureEnabled = None
            class timeline:
                currentTime = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class fonts:
                size = None
                onloading = None
                onloadingdone = None
                onloadingerror = None
                ready = None
                status = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                add = None
                addEventListener = None
                check = None
                clear = None
                delete = None
                dispatchEvent = None
                entries = None
                forEach = None
                has = None
                hasOwnProperty = None
                isPrototypeOf = None
                keys = None
                load = None
                propertyIsEnumerable = None
                removeEventListener = None
                toLocaleString = None
                toString = None
                valueOf = None
                values = None

            class scrollingElement:
                aLink = None
                background = None
                bgColor = None
                link = None
                text = None
                vLink = None
                onblur = None
                onerror = None
                onfocus = None
                onfocusin = None
                onfocusout = None
                onload = None
                onresize = None
                onscroll = None
                onwebkitmouseforcechanged = None
                onwebkitmouseforcedown = None
                onwebkitmouseforcewillbegin = None
                onwebkitmouseforceup = None
                onselectionchange = None
                onorientationchange = None
                onafterprint = None
                onbeforeprint = None
                onbeforeunload = None
                onhashchange = None
                onlanguagechange = None
                onmessage = None
                onoffline = None
                ononline = None
                onpagehide = None
                onpageshow = None
                onpopstate = None
                onrejectionhandled = None
                onstorage = None
                onunhandledrejection = None
                onunload = None
                title = None
                lang = None
                translate = None
                dir = None
                hidden = None
                accessKey = None
                accessKeyLabel = None
                draggable = None
                spellcheck = None
                autocapitalize = None
                innerText = None
                outerText = None
                autocorrect = None
                webkitdropzone = None
                style = None
                oncopy = None
                oncut = None
                onpaste = None
                onbeforecopy = None
                onbeforecut = None
                onbeforeinput = None
                onbeforepaste = None
                contentEditable = None
                enterKeyHint = None
                isContentEditable = None
                inputMode = None
                onabort = None
                oncanplay = None
                oncanplaythrough = None
                onchange = None
                onclick = None
                onclose = None
                oncontextmenu = None
                oncuechange = None
                ondblclick = None
                ondrag = None
                ondragend = None
                ondragenter = None
                ondragleave = None
                ondragover = None
                ondragstart = None
                ondrop = None
                ondurationchange = None
                onemptied = None
                onended = None
                onformdata = None
                oninput = None
                oninvalid = None
                onkeydown = None
                onkeypress = None
                onkeyup = None
                onloadeddata = None
                onloadedmetadata = None
                onloadstart = None
                onmousedown = None
                onmouseenter = None
                onmouseleave = None
                onmousemove = None
                onmouseout = None
                onmouseover = None
                onmouseup = None
                onpause = None
                onplay = None
                onplaying = None
                onprogress = None
                onratechange = None
                onreset = None
                onseeked = None
                onseeking = None
                onselect = None
                onslotchange = None
                onstalled = None
                onsubmit = None
                onsuspend = None
                ontimeupdate = None
                ontoggle = None
                onvolumechange = None
                onwaiting = None
                onwebkitanimationend = None
                onwebkitanimationiteration = None
                onwebkitanimationstart = None
                onwebkittransitionend = None
                onwheel = None
                onmousewheel = None
                onsearch = None
                ontouchcancel = None
                ontouchend = None
                ontouchmove = None
                ontouchstart = None
                ontouchforcechange = None
                onanimationstart = None
                onanimationiteration = None
                onanimationend = None
                onanimationcancel = None
                ontransitionrun = None
                ontransitionstart = None
                ontransitionend = None
                ontransitioncancel = None
                ongotpointercapture = None
                onlostpointercapture = None
                onpointerdown = None
                onpointermove = None
                onpointerup = None
                onpointercancel = None
                onpointerover = None
                onpointerout = None
                onpointerenter = None
                onpointerleave = None
                onselectstart = None
                offsetParent = None
                offsetTop = None
                offsetLeft = None
                offsetWidth = None
                offsetHeight = None
                dataset = None
                tabIndex = None
                namespaceURI = None
                prefix = None
                localName = None
                tagName = None
                id = None
                className = None
                classList = None
                slot = None
                part = None
                attributes = None
                shadowRoot = None
                ongesturechange = None
                ongestureend = None
                ongesturestart = None
                onbeforeload = None
                onwebkitneedkey = None
                onwebkitpresentationmodechanged = None
                onwebkitcurrentplaybacktargetiswirelesschanged = None
                onwebkitplaybacktargetavailabilitychanged = None
                role = None
                ariaAtomic = None
                ariaAutoComplete = None
                ariaBusy = None
                ariaChecked = None
                ariaColCount = None
                ariaColIndex = None
                ariaColSpan = None
                ariaCurrent = None
                ariaDisabled = None
                ariaExpanded = None
                ariaHasPopup = None
                ariaHidden = None
                ariaInvalid = None
                ariaKeyShortcuts = None
                ariaLabel = None
                ariaLevel = None
                ariaLive = None
                ariaModal = None
                ariaMultiLine = None
                ariaMultiSelectable = None
                ariaOrientation = None
                ariaPlaceholder = None
                ariaPosInSet = None
                ariaPressed = None
                ariaReadOnly = None
                ariaRelevant = None
                ariaRequired = None
                ariaRoleDescription = None
                ariaRowCount = None
                ariaRowIndex = None
                ariaRowSpan = None
                ariaSelected = None
                ariaSetSize = None
                ariaSort = None
                ariaValueMax = None
                ariaValueMin = None
                ariaValueNow = None
                ariaValueText = None
                scrollTop = None
                scrollLeft = None
                scrollWidth = None
                scrollHeight = None
                clientTop = None
                clientLeft = None
                clientWidth = None
                clientHeight = None
                outerHTML = None
                innerHTML = None
                previousElementSibling = None
                nextElementSibling = None
                children = None
                firstElementChild = None
                lastElementChild = None
                childElementCount = None
                assignedSlot = None
                nodeType = None
                nodeName = None
                baseURI = None
                isConnected = None
                ownerDocument = None
                parentNode = None
                parentElement = None
                childNodes = None
                firstChild = None
                lastChild = None
                previousSibling = None
                nextSibling = None
                nodeValue = None
                textContent = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                addEventListener = None
                after = None
                animate = None
                append = None
                appendChild = None
                attachShadow = None
                before = None
                blur = None
                click = None
                cloneNode = None
                closest = None
                compareDocumentPosition = None
                contains = None
                dispatchEvent = None
                focus = None
                getAnimations = None
                getAttribute = None
                getAttributeNS = None
                getAttributeNames = None
                getAttributeNode = None
                getAttributeNodeNS = None
                getBoundingClientRect = None
                getClientRects = None
                getElementsByClassName = None
                getElementsByTagName = None
                getElementsByTagNameNS = None
                getRootNode = None
                hasAttribute = None
                hasAttributeNS = None
                hasAttributes = None
                hasChildNodes = None
                hasOwnProperty = None
                hasPointerCapture = None
                insertAdjacentElement = None
                insertAdjacentHTML = None
                insertAdjacentText = None
                insertBefore = None
                isDefaultNamespace = None
                isEqualNode = None
                isPrototypeOf = None
                isSameNode = None
                lookupNamespaceURI = None
                lookupPrefix = None
                matches = None
                normalize = None
                prepend = None
                propertyIsEnumerable = None
                querySelector = None
                querySelectorAll = None
                releasePointerCapture = None
                remove = None
                removeAttribute = None
                removeAttributeNS = None
                removeAttributeNode = None
                removeChild = None
                removeEventListener = None
                replaceChild = None
                replaceChildren = None
                replaceWith = None
                scroll = None
                scrollBy = None
                scrollIntoView = None
                scrollIntoViewIfNeeded = None
                scrollTo = None
                setAttribute = None
                setAttributeNS = None
                setAttributeNode = None
                setAttributeNodeNS = None
                setPointerCapture = None
                toLocaleString = None
                toString = None
                toggleAttribute = None
                valueOf = None
                webkitMatchesSelector = None

            domain = None
            referrer = None
            cookie = None
            lastModified = None
            readyState = None
            title = None
            dir = None
            class body:
                aLink = None
                background = None
                bgColor = None
                link = None
                text = None
                vLink = None
                onblur = None
                onerror = None
                onfocus = None
                onfocusin = None
                onfocusout = None
                onload = None
                onresize = None
                onscroll = None
                onwebkitmouseforcechanged = None
                onwebkitmouseforcedown = None
                onwebkitmouseforcewillbegin = None
                onwebkitmouseforceup = None
                onselectionchange = None
                onorientationchange = None
                onafterprint = None
                onbeforeprint = None
                onbeforeunload = None
                onhashchange = None
                onlanguagechange = None
                onmessage = None
                onoffline = None
                ononline = None
                onpagehide = None
                onpageshow = None
                onpopstate = None
                onrejectionhandled = None
                onstorage = None
                onunhandledrejection = None
                onunload = None
                title = None
                lang = None
                translate = None
                dir = None
                hidden = None
                accessKey = None
                accessKeyLabel = None
                draggable = None
                spellcheck = None
                autocapitalize = None
                innerText = None
                outerText = None
                autocorrect = None
                webkitdropzone = None
                style = None
                oncopy = None
                oncut = None
                onpaste = None
                onbeforecopy = None
                onbeforecut = None
                onbeforeinput = None
                onbeforepaste = None
                contentEditable = None
                enterKeyHint = None
                isContentEditable = None
                inputMode = None
                onabort = None
                oncanplay = None
                oncanplaythrough = None
                onchange = None
                onclick = None
                onclose = None
                oncontextmenu = None
                oncuechange = None
                ondblclick = None
                ondrag = None
                ondragend = None
                ondragenter = None
                ondragleave = None
                ondragover = None
                ondragstart = None
                ondrop = None
                ondurationchange = None
                onemptied = None
                onended = None
                onformdata = None
                oninput = None
                oninvalid = None
                onkeydown = None
                onkeypress = None
                onkeyup = None
                onloadeddata = None
                onloadedmetadata = None
                onloadstart = None
                onmousedown = None
                onmouseenter = None
                onmouseleave = None
                onmousemove = None
                onmouseout = None
                onmouseover = None
                onmouseup = None
                onpause = None
                onplay = None
                onplaying = None
                onprogress = None
                onratechange = None
                onreset = None
                onseeked = None
                onseeking = None
                onselect = None
                onslotchange = None
                onstalled = None
                onsubmit = None
                onsuspend = None
                ontimeupdate = None
                ontoggle = None
                onvolumechange = None
                onwaiting = None
                onwebkitanimationend = None
                onwebkitanimationiteration = None
                onwebkitanimationstart = None
                onwebkittransitionend = None
                onwheel = None
                onmousewheel = None
                onsearch = None
                ontouchcancel = None
                ontouchend = None
                ontouchmove = None
                ontouchstart = None
                ontouchforcechange = None
                onanimationstart = None
                onanimationiteration = None
                onanimationend = None
                onanimationcancel = None
                ontransitionrun = None
                ontransitionstart = None
                ontransitionend = None
                ontransitioncancel = None
                ongotpointercapture = None
                onlostpointercapture = None
                onpointerdown = None
                onpointermove = None
                onpointerup = None
                onpointercancel = None
                onpointerover = None
                onpointerout = None
                onpointerenter = None
                onpointerleave = None
                onselectstart = None
                offsetParent = None
                offsetTop = None
                offsetLeft = None
                offsetWidth = None
                offsetHeight = None
                dataset = None
                tabIndex = None
                namespaceURI = None
                prefix = None
                localName = None
                tagName = None
                id = None
                className = None
                classList = None
                slot = None
                part = None
                attributes = None
                shadowRoot = None
                ongesturechange = None
                ongestureend = None
                ongesturestart = None
                onbeforeload = None
                onwebkitneedkey = None
                onwebkitpresentationmodechanged = None
                onwebkitcurrentplaybacktargetiswirelesschanged = None
                onwebkitplaybacktargetavailabilitychanged = None
                role = None
                ariaAtomic = None
                ariaAutoComplete = None
                ariaBusy = None
                ariaChecked = None
                ariaColCount = None
                ariaColIndex = None
                ariaColSpan = None
                ariaCurrent = None
                ariaDisabled = None
                ariaExpanded = None
                ariaHasPopup = None
                ariaHidden = None
                ariaInvalid = None
                ariaKeyShortcuts = None
                ariaLabel = None
                ariaLevel = None
                ariaLive = None
                ariaModal = None
                ariaMultiLine = None
                ariaMultiSelectable = None
                ariaOrientation = None
                ariaPlaceholder = None
                ariaPosInSet = None
                ariaPressed = None
                ariaReadOnly = None
                ariaRelevant = None
                ariaRequired = None
                ariaRoleDescription = None
                ariaRowCount = None
                ariaRowIndex = None
                ariaRowSpan = None
                ariaSelected = None
                ariaSetSize = None
                ariaSort = None
                ariaValueMax = None
                ariaValueMin = None
                ariaValueNow = None
                ariaValueText = None
                scrollTop = None
                scrollLeft = None
                scrollWidth = None
                scrollHeight = None
                clientTop = None
                clientLeft = None
                clientWidth = None
                clientHeight = None
                outerHTML = None
                innerHTML = None
                previousElementSibling = None
                nextElementSibling = None
                children = None
                firstElementChild = None
                lastElementChild = None
                childElementCount = None
                assignedSlot = None
                nodeType = None
                nodeName = None
                baseURI = None
                isConnected = None
                ownerDocument = None
                parentNode = None
                parentElement = None
                childNodes = None
                firstChild = None
                lastChild = None
                previousSibling = None
                nextSibling = None
                nodeValue = None
                textContent = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                addEventListener = None
                after = None
                animate = None
                append = None
                appendChild = None
                attachShadow = None
                before = None
                blur = None
                click = None
                cloneNode = None
                closest = None
                compareDocumentPosition = None
                contains = None
                dispatchEvent = None
                focus = None
                getAnimations = None
                getAttribute = None
                getAttributeNS = None
                getAttributeNames = None
                getAttributeNode = None
                getAttributeNodeNS = None
                getBoundingClientRect = None
                getClientRects = None
                getElementsByClassName = None
                getElementsByTagName = None
                getElementsByTagNameNS = None
                getRootNode = None
                hasAttribute = None
                hasAttributeNS = None
                hasAttributes = None
                hasChildNodes = None
                hasOwnProperty = None
                hasPointerCapture = None
                insertAdjacentElement = None
                insertAdjacentHTML = None
                insertAdjacentText = None
                insertBefore = None
                isDefaultNamespace = None
                isEqualNode = None
                isPrototypeOf = None
                isSameNode = None
                lookupNamespaceURI = None
                lookupPrefix = None
                matches = None
                normalize = None
                prepend = None
                propertyIsEnumerable = None
                querySelector = None
                querySelectorAll = None
                releasePointerCapture = None
                remove = None
                removeAttribute = None
                removeAttributeNS = None
                removeAttributeNode = None
                removeChild = None
                removeEventListener = None
                replaceChild = None
                replaceChildren = None
                replaceWith = None
                scroll = None
                scrollBy = None
                scrollIntoView = None
                scrollIntoViewIfNeeded = None
                scrollTo = None
                setAttribute = None
                setAttributeNS = None
                setAttributeNode = None
                setAttributeNodeNS = None
                setPointerCapture = None
                toLocaleString = None
                toString = None
                toggleAttribute = None
                valueOf = None
                webkitMatchesSelector = None

            class head:
                profile = None
                title = None
                lang = None
                translate = None
                dir = None
                hidden = None
                accessKey = None
                accessKeyLabel = None
                draggable = None
                spellcheck = None
                autocapitalize = None
                innerText = None
                outerText = None
                autocorrect = None
                webkitdropzone = None
                style = None
                oncopy = None
                oncut = None
                onpaste = None
                onbeforecopy = None
                onbeforecut = None
                onbeforeinput = None
                onbeforepaste = None
                contentEditable = None
                enterKeyHint = None
                isContentEditable = None
                inputMode = None
                onabort = None
                onblur = None
                oncanplay = None
                oncanplaythrough = None
                onchange = None
                onclick = None
                onclose = None
                oncontextmenu = None
                oncuechange = None
                ondblclick = None
                ondrag = None
                ondragend = None
                ondragenter = None
                ondragleave = None
                ondragover = None
                ondragstart = None
                ondrop = None
                ondurationchange = None
                onemptied = None
                onended = None
                onerror = None
                onfocus = None
                onformdata = None
                oninput = None
                oninvalid = None
                onkeydown = None
                onkeypress = None
                onkeyup = None
                onload = None
                onloadeddata = None
                onloadedmetadata = None
                onloadstart = None
                onmousedown = None
                onmouseenter = None
                onmouseleave = None
                onmousemove = None
                onmouseout = None
                onmouseover = None
                onmouseup = None
                onpause = None
                onplay = None
                onplaying = None
                onprogress = None
                onratechange = None
                onreset = None
                onresize = None
                onscroll = None
                onseeked = None
                onseeking = None
                onselect = None
                onslotchange = None
                onstalled = None
                onsubmit = None
                onsuspend = None
                ontimeupdate = None
                ontoggle = None
                onvolumechange = None
                onwaiting = None
                onwebkitanimationend = None
                onwebkitanimationiteration = None
                onwebkitanimationstart = None
                onwebkittransitionend = None
                onwheel = None
                onmousewheel = None
                onsearch = None
                ontouchcancel = None
                ontouchend = None
                ontouchmove = None
                ontouchstart = None
                ontouchforcechange = None
                onwebkitmouseforcechanged = None
                onwebkitmouseforcedown = None
                onwebkitmouseforcewillbegin = None
                onwebkitmouseforceup = None
                onanimationstart = None
                onanimationiteration = None
                onanimationend = None
                onanimationcancel = None
                ontransitionrun = None
                ontransitionstart = None
                ontransitionend = None
                ontransitioncancel = None
                ongotpointercapture = None
                onlostpointercapture = None
                onpointerdown = None
                onpointermove = None
                onpointerup = None
                onpointercancel = None
                onpointerover = None
                onpointerout = None
                onpointerenter = None
                onpointerleave = None
                onselectstart = None
                onselectionchange = None
                offsetParent = None
                offsetTop = None
                offsetLeft = None
                offsetWidth = None
                offsetHeight = None
                dataset = None
                tabIndex = None
                namespaceURI = None
                prefix = None
                localName = None
                tagName = None
                id = None
                className = None
                classList = None
                slot = None
                part = None
                attributes = None
                shadowRoot = None
                onfocusin = None
                onfocusout = None
                ongesturechange = None
                ongestureend = None
                ongesturestart = None
                onbeforeload = None
                onwebkitneedkey = None
                onwebkitpresentationmodechanged = None
                onwebkitcurrentplaybacktargetiswirelesschanged = None
                onwebkitplaybacktargetavailabilitychanged = None
                role = None
                ariaAtomic = None
                ariaAutoComplete = None
                ariaBusy = None
                ariaChecked = None
                ariaColCount = None
                ariaColIndex = None
                ariaColSpan = None
                ariaCurrent = None
                ariaDisabled = None
                ariaExpanded = None
                ariaHasPopup = None
                ariaHidden = None
                ariaInvalid = None
                ariaKeyShortcuts = None
                ariaLabel = None
                ariaLevel = None
                ariaLive = None
                ariaModal = None
                ariaMultiLine = None
                ariaMultiSelectable = None
                ariaOrientation = None
                ariaPlaceholder = None
                ariaPosInSet = None
                ariaPressed = None
                ariaReadOnly = None
                ariaRelevant = None
                ariaRequired = None
                ariaRoleDescription = None
                ariaRowCount = None
                ariaRowIndex = None
                ariaRowSpan = None
                ariaSelected = None
                ariaSetSize = None
                ariaSort = None
                ariaValueMax = None
                ariaValueMin = None
                ariaValueNow = None
                ariaValueText = None
                scrollTop = None
                scrollLeft = None
                scrollWidth = None
                scrollHeight = None
                clientTop = None
                clientLeft = None
                clientWidth = None
                clientHeight = None
                outerHTML = None
                innerHTML = None
                previousElementSibling = None
                nextElementSibling = None
                children = None
                firstElementChild = None
                lastElementChild = None
                childElementCount = None
                assignedSlot = None
                nodeType = None
                nodeName = None
                baseURI = None
                isConnected = None
                ownerDocument = None
                parentNode = None
                parentElement = None
                childNodes = None
                firstChild = None
                lastChild = None
                previousSibling = None
                nextSibling = None
                nodeValue = None
                textContent = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                addEventListener = None
                after = None
                animate = None
                append = None
                appendChild = None
                attachShadow = None
                before = None
                blur = None
                click = None
                cloneNode = None
                closest = None
                compareDocumentPosition = None
                contains = None
                dispatchEvent = None
                focus = None
                getAnimations = None
                getAttribute = None
                getAttributeNS = None
                getAttributeNames = None
                getAttributeNode = None
                getAttributeNodeNS = None
                getBoundingClientRect = None
                getClientRects = None
                getElementsByClassName = None
                getElementsByTagName = None
                getElementsByTagNameNS = None
                getRootNode = None
                hasAttribute = None
                hasAttributeNS = None
                hasAttributes = None
                hasChildNodes = None
                hasOwnProperty = None
                hasPointerCapture = None
                insertAdjacentElement = None
                insertAdjacentHTML = None
                insertAdjacentText = None
                insertBefore = None
                isDefaultNamespace = None
                isEqualNode = None
                isPrototypeOf = None
                isSameNode = None
                lookupNamespaceURI = None
                lookupPrefix = None
                matches = None
                normalize = None
                prepend = None
                propertyIsEnumerable = None
                querySelector = None
                querySelectorAll = None
                releasePointerCapture = None
                remove = None
                removeAttribute = None
                removeAttributeNS = None
                removeAttributeNode = None
                removeChild = None
                removeEventListener = None
                replaceChild = None
                replaceChildren = None
                replaceWith = None
                scroll = None
                scrollBy = None
                scrollIntoView = None
                scrollIntoViewIfNeeded = None
                scrollTo = None
                setAttribute = None
                setAttributeNS = None
                setAttributeNode = None
                setAttributeNodeNS = None
                setPointerCapture = None
                toLocaleString = None
                toString = None
                toggleAttribute = None
                valueOf = None
                webkitMatchesSelector = None

            class images:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class embeds:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class plugins:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class links:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class forms:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class scripts:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            currentScript = None

            designMode = None
            onreadystatechange = None

            fgColor = None
            linkColor = None
            vlinkColor = None
            alinkColor = None
            bgColor = None
            class anchors:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class applets:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            hidden = None
            visibilityState = None
            onvisibilitychange = None

            oncopy = None

            oncut = None

            onpaste = None

            onbeforecopy = None

            onbeforecut = None

            onbeforeinput = None

            onbeforepaste = None

            class activeElement:
                aLink = None
                background = None
                bgColor = None
                link = None
                text = None
                vLink = None
                onblur = None
                onerror = None
                onfocus = None
                onfocusin = None
                onfocusout = None
                onload = None
                onresize = None
                onscroll = None
                onwebkitmouseforcechanged = None
                onwebkitmouseforcedown = None
                onwebkitmouseforcewillbegin = None
                onwebkitmouseforceup = None
                onselectionchange = None
                onorientationchange = None
                onafterprint = None
                onbeforeprint = None
                onbeforeunload = None
                onhashchange = None
                onlanguagechange = None
                onmessage = None
                onoffline = None
                ononline = None
                onpagehide = None
                onpageshow = None
                onpopstate = None
                onrejectionhandled = None
                onstorage = None
                onunhandledrejection = None
                onunload = None
                title = None
                lang = None
                translate = None
                dir = None
                hidden = None
                accessKey = None
                accessKeyLabel = None
                draggable = None
                spellcheck = None
                autocapitalize = None
                innerText = None
                outerText = None
                autocorrect = None
                webkitdropzone = None
                style = None
                oncopy = None
                oncut = None
                onpaste = None
                onbeforecopy = None
                onbeforecut = None
                onbeforeinput = None
                onbeforepaste = None
                contentEditable = None
                enterKeyHint = None
                isContentEditable = None
                inputMode = None
                onabort = None
                oncanplay = None
                oncanplaythrough = None
                onchange = None
                onclick = None
                onclose = None
                oncontextmenu = None
                oncuechange = None
                ondblclick = None
                ondrag = None
                ondragend = None
                ondragenter = None
                ondragleave = None
                ondragover = None
                ondragstart = None
                ondrop = None
                ondurationchange = None
                onemptied = None
                onended = None
                onformdata = None
                oninput = None
                oninvalid = None
                onkeydown = None
                onkeypress = None
                onkeyup = None
                onloadeddata = None
                onloadedmetadata = None
                onloadstart = None
                onmousedown = None
                onmouseenter = None
                onmouseleave = None
                onmousemove = None
                onmouseout = None
                onmouseover = None
                onmouseup = None
                onpause = None
                onplay = None
                onplaying = None
                onprogress = None
                onratechange = None
                onreset = None
                onseeked = None
                onseeking = None
                onselect = None
                onslotchange = None
                onstalled = None
                onsubmit = None
                onsuspend = None
                ontimeupdate = None
                ontoggle = None
                onvolumechange = None
                onwaiting = None
                onwebkitanimationend = None
                onwebkitanimationiteration = None
                onwebkitanimationstart = None
                onwebkittransitionend = None
                onwheel = None
                onmousewheel = None
                onsearch = None
                ontouchcancel = None
                ontouchend = None
                ontouchmove = None
                ontouchstart = None
                ontouchforcechange = None
                onanimationstart = None
                onanimationiteration = None
                onanimationend = None
                onanimationcancel = None
                ontransitionrun = None
                ontransitionstart = None
                ontransitionend = None
                ontransitioncancel = None
                ongotpointercapture = None
                onlostpointercapture = None
                onpointerdown = None
                onpointermove = None
                onpointerup = None
                onpointercancel = None
                onpointerover = None
                onpointerout = None
                onpointerenter = None
                onpointerleave = None
                onselectstart = None
                offsetParent = None
                offsetTop = None
                offsetLeft = None
                offsetWidth = None
                offsetHeight = None
                dataset = None
                tabIndex = None
                namespaceURI = None
                prefix = None
                localName = None
                tagName = None
                id = None
                className = None
                classList = None
                slot = None
                part = None
                attributes = None
                shadowRoot = None
                ongesturechange = None
                ongestureend = None
                ongesturestart = None
                onbeforeload = None
                onwebkitneedkey = None
                onwebkitpresentationmodechanged = None
                onwebkitcurrentplaybacktargetiswirelesschanged = None
                onwebkitplaybacktargetavailabilitychanged = None
                role = None
                ariaAtomic = None
                ariaAutoComplete = None
                ariaBusy = None
                ariaChecked = None
                ariaColCount = None
                ariaColIndex = None
                ariaColSpan = None
                ariaCurrent = None
                ariaDisabled = None
                ariaExpanded = None
                ariaHasPopup = None
                ariaHidden = None
                ariaInvalid = None
                ariaKeyShortcuts = None
                ariaLabel = None
                ariaLevel = None
                ariaLive = None
                ariaModal = None
                ariaMultiLine = None
                ariaMultiSelectable = None
                ariaOrientation = None
                ariaPlaceholder = None
                ariaPosInSet = None
                ariaPressed = None
                ariaReadOnly = None
                ariaRelevant = None
                ariaRequired = None
                ariaRoleDescription = None
                ariaRowCount = None
                ariaRowIndex = None
                ariaRowSpan = None
                ariaSelected = None
                ariaSetSize = None
                ariaSort = None
                ariaValueMax = None
                ariaValueMin = None
                ariaValueNow = None
                ariaValueText = None
                scrollTop = None
                scrollLeft = None
                scrollWidth = None
                scrollHeight = None
                clientTop = None
                clientLeft = None
                clientWidth = None
                clientHeight = None
                outerHTML = None
                innerHTML = None
                previousElementSibling = None
                nextElementSibling = None
                children = None
                firstElementChild = None
                lastElementChild = None
                childElementCount = None
                assignedSlot = None
                nodeType = None
                nodeName = None
                baseURI = None
                isConnected = None
                ownerDocument = None
                parentNode = None
                parentElement = None
                childNodes = None
                firstChild = None
                lastChild = None
                previousSibling = None
                nextSibling = None
                nodeValue = None
                textContent = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                addEventListener = None
                after = None
                animate = None
                append = None
                appendChild = None
                attachShadow = None
                before = None
                blur = None
                click = None
                cloneNode = None
                closest = None
                compareDocumentPosition = None
                contains = None
                dispatchEvent = None
                focus = None
                getAnimations = None
                getAttribute = None
                getAttributeNS = None
                getAttributeNames = None
                getAttributeNode = None
                getAttributeNodeNS = None
                getBoundingClientRect = None
                getClientRects = None
                getElementsByClassName = None
                getElementsByTagName = None
                getElementsByTagNameNS = None
                getRootNode = None
                hasAttribute = None
                hasAttributeNS = None
                hasAttributes = None
                hasChildNodes = None
                hasOwnProperty = None
                hasPointerCapture = None
                insertAdjacentElement = None
                insertAdjacentHTML = None
                insertAdjacentText = None
                insertBefore = None
                isDefaultNamespace = None
                isEqualNode = None
                isPrototypeOf = None
                isSameNode = None
                lookupNamespaceURI = None
                lookupPrefix = None
                matches = None
                normalize = None
                prepend = None
                propertyIsEnumerable = None
                querySelector = None
                querySelectorAll = None
                releasePointerCapture = None
                remove = None
                removeAttribute = None
                removeAttributeNS = None
                removeAttributeNode = None
                removeChild = None
                removeEventListener = None
                replaceChild = None
                replaceChildren = None
                replaceWith = None
                scroll = None
                scrollBy = None
                scrollIntoView = None
                scrollIntoViewIfNeeded = None
                scrollTo = None
                setAttribute = None
                setAttributeNS = None
                setAttributeNode = None
                setAttributeNodeNS = None
                setPointerCapture = None
                toLocaleString = None
                toString = None
                toggleAttribute = None
                valueOf = None
                webkitMatchesSelector = None

            pictureInPictureElement = None

            class styleSheets:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            onabort = None

            onblur = None

            oncanplay = None

            oncanplaythrough = None

            onchange = None

            onclick = None

            onclose = None

            oncontextmenu = None

            oncuechange = None

            ondblclick = None

            ondrag = None

            ondragend = None

            ondragenter = None

            ondragleave = None

            ondragover = None

            ondragstart = None

            ondrop = None

            ondurationchange = None

            onemptied = None

            onended = None

            onerror = None

            onfocus = None

            onformdata = None

            oninput = None

            oninvalid = None

            onkeydown = None

            onkeypress = None

            onkeyup = None

            onload = None

            onloadeddata = None

            onloadedmetadata = None

            onloadstart = None

            onmousedown = None

            onmouseenter = None

            onmouseleave = None

            onmousemove = None

            onmouseout = None

            onmouseover = None

            onmouseup = None

            onpause = None

            onplay = None

            onplaying = None

            onprogress = None

            onratechange = None

            onreset = None

            onresize = None

            onscroll = None

            onseeked = None

            onseeking = None

            onselect = None

            onslotchange = None

            onstalled = None

            onsubmit = None

            onsuspend = None

            ontimeupdate = None

            ontoggle = None

            onvolumechange = None

            onwaiting = None

            onwebkitanimationend = None

            onwebkitanimationiteration = None

            onwebkitanimationstart = None

            onwebkittransitionend = None

            onwheel = None

            onmousewheel = None

            onsearch = None

            ontouchcancel = None

            ontouchend = None

            ontouchmove = None

            ontouchstart = None

            ontouchforcechange = None

            onwebkitmouseforcechanged = None

            onwebkitmouseforcedown = None

            onwebkitmouseforcewillbegin = None

            onwebkitmouseforceup = None

            onanimationstart = None

            onanimationiteration = None

            onanimationend = None

            onanimationcancel = None

            ontransitionrun = None

            ontransitionstart = None

            ontransitionend = None

            ontransitioncancel = None

            ongotpointercapture = None

            onlostpointercapture = None

            onpointerdown = None

            onpointermove = None

            onpointerup = None

            onpointercancel = None

            onpointerover = None

            onpointerout = None

            onpointerenter = None

            onpointerleave = None

            onselectstart = None

            onselectionchange = None

            class children:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class firstElementChild:
                version = None
                manifest = None
                title = None
                lang = None
                translate = None
                dir = None
                hidden = None
                accessKey = None
                accessKeyLabel = None
                draggable = None
                spellcheck = None
                autocapitalize = None
                innerText = None
                outerText = None
                autocorrect = None
                webkitdropzone = None
                style = None
                oncopy = None
                oncut = None
                onpaste = None
                onbeforecopy = None
                onbeforecut = None
                onbeforeinput = None
                onbeforepaste = None
                contentEditable = None
                enterKeyHint = None
                isContentEditable = None
                inputMode = None
                onabort = None
                onblur = None
                oncanplay = None
                oncanplaythrough = None
                onchange = None
                onclick = None
                onclose = None
                oncontextmenu = None
                oncuechange = None
                ondblclick = None
                ondrag = None
                ondragend = None
                ondragenter = None
                ondragleave = None
                ondragover = None
                ondragstart = None
                ondrop = None
                ondurationchange = None
                onemptied = None
                onended = None
                onerror = None
                onfocus = None
                onformdata = None
                oninput = None
                oninvalid = None
                onkeydown = None
                onkeypress = None
                onkeyup = None
                onload = None
                onloadeddata = None
                onloadedmetadata = None
                onloadstart = None
                onmousedown = None
                onmouseenter = None
                onmouseleave = None
                onmousemove = None
                onmouseout = None
                onmouseover = None
                onmouseup = None
                onpause = None
                onplay = None
                onplaying = None
                onprogress = None
                onratechange = None
                onreset = None
                onresize = None
                onscroll = None
                onseeked = None
                onseeking = None
                onselect = None
                onslotchange = None
                onstalled = None
                onsubmit = None
                onsuspend = None
                ontimeupdate = None
                ontoggle = None
                onvolumechange = None
                onwaiting = None
                onwebkitanimationend = None
                onwebkitanimationiteration = None
                onwebkitanimationstart = None
                onwebkittransitionend = None
                onwheel = None
                onmousewheel = None
                onsearch = None
                ontouchcancel = None
                ontouchend = None
                ontouchmove = None
                ontouchstart = None
                ontouchforcechange = None
                onwebkitmouseforcechanged = None
                onwebkitmouseforcedown = None
                onwebkitmouseforcewillbegin = None
                onwebkitmouseforceup = None
                onanimationstart = None
                onanimationiteration = None
                onanimationend = None
                onanimationcancel = None
                ontransitionrun = None
                ontransitionstart = None
                ontransitionend = None
                ontransitioncancel = None
                ongotpointercapture = None
                onlostpointercapture = None
                onpointerdown = None
                onpointermove = None
                onpointerup = None
                onpointercancel = None
                onpointerover = None
                onpointerout = None
                onpointerenter = None
                onpointerleave = None
                onselectstart = None
                onselectionchange = None
                offsetParent = None
                offsetTop = None
                offsetLeft = None
                offsetWidth = None
                offsetHeight = None
                dataset = None
                tabIndex = None
                namespaceURI = None
                prefix = None
                localName = None
                tagName = None
                id = None
                className = None
                classList = None
                slot = None
                part = None
                attributes = None
                shadowRoot = None
                onfocusin = None
                onfocusout = None
                ongesturechange = None
                ongestureend = None
                ongesturestart = None
                onbeforeload = None
                onwebkitneedkey = None
                onwebkitpresentationmodechanged = None
                onwebkitcurrentplaybacktargetiswirelesschanged = None
                onwebkitplaybacktargetavailabilitychanged = None
                role = None
                ariaAtomic = None
                ariaAutoComplete = None
                ariaBusy = None
                ariaChecked = None
                ariaColCount = None
                ariaColIndex = None
                ariaColSpan = None
                ariaCurrent = None
                ariaDisabled = None
                ariaExpanded = None
                ariaHasPopup = None
                ariaHidden = None
                ariaInvalid = None
                ariaKeyShortcuts = None
                ariaLabel = None
                ariaLevel = None
                ariaLive = None
                ariaModal = None
                ariaMultiLine = None
                ariaMultiSelectable = None
                ariaOrientation = None
                ariaPlaceholder = None
                ariaPosInSet = None
                ariaPressed = None
                ariaReadOnly = None
                ariaRelevant = None
                ariaRequired = None
                ariaRoleDescription = None
                ariaRowCount = None
                ariaRowIndex = None
                ariaRowSpan = None
                ariaSelected = None
                ariaSetSize = None
                ariaSort = None
                ariaValueMax = None
                ariaValueMin = None
                ariaValueNow = None
                ariaValueText = None
                scrollTop = None
                scrollLeft = None
                scrollWidth = None
                scrollHeight = None
                clientTop = None
                clientLeft = None
                clientWidth = None
                clientHeight = None
                outerHTML = None
                innerHTML = None
                previousElementSibling = None
                nextElementSibling = None
                children = None
                firstElementChild = None
                lastElementChild = None
                childElementCount = None
                assignedSlot = None
                nodeType = None
                nodeName = None
                baseURI = None
                isConnected = None
                ownerDocument = None
                parentNode = None
                parentElement = None
                childNodes = None
                firstChild = None
                lastChild = None
                previousSibling = None
                nextSibling = None
                nodeValue = None
                textContent = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                addEventListener = None
                after = None
                animate = None
                append = None
                appendChild = None
                attachShadow = None
                before = None
                blur = None
                click = None
                cloneNode = None
                closest = None
                compareDocumentPosition = None
                contains = None
                dispatchEvent = None
                focus = None
                getAnimations = None
                getAttribute = None
                getAttributeNS = None
                getAttributeNames = None
                getAttributeNode = None
                getAttributeNodeNS = None
                getBoundingClientRect = None
                getClientRects = None
                getElementsByClassName = None
                getElementsByTagName = None
                getElementsByTagNameNS = None
                getRootNode = None
                hasAttribute = None
                hasAttributeNS = None
                hasAttributes = None
                hasChildNodes = None
                hasOwnProperty = None
                hasPointerCapture = None
                insertAdjacentElement = None
                insertAdjacentHTML = None
                insertAdjacentText = None
                insertBefore = None
                isDefaultNamespace = None
                isEqualNode = None
                isPrototypeOf = None
                isSameNode = None
                lookupNamespaceURI = None
                lookupPrefix = None
                matches = None
                normalize = None
                prepend = None
                propertyIsEnumerable = None
                querySelector = None
                querySelectorAll = None
                releasePointerCapture = None
                remove = None
                removeAttribute = None
                removeAttributeNS = None
                removeAttributeNode = None
                removeChild = None
                removeEventListener = None
                replaceChild = None
                replaceChildren = None
                replaceWith = None
                scroll = None
                scrollBy = None
                scrollIntoView = None
                scrollIntoViewIfNeeded = None
                scrollTo = None
                setAttribute = None
                setAttributeNS = None
                setAttributeNode = None
                setAttributeNodeNS = None
                setPointerCapture = None
                toLocaleString = None
                toString = None
                toggleAttribute = None
                valueOf = None
                webkitMatchesSelector = None

            class lastElementChild:
                version = None
                manifest = None
                title = None
                lang = None
                translate = None
                dir = None
                hidden = None
                accessKey = None
                accessKeyLabel = None
                draggable = None
                spellcheck = None
                autocapitalize = None
                innerText = None
                outerText = None
                autocorrect = None
                webkitdropzone = None
                style = None
                oncopy = None
                oncut = None
                onpaste = None
                onbeforecopy = None
                onbeforecut = None
                onbeforeinput = None
                onbeforepaste = None
                contentEditable = None
                enterKeyHint = None
                isContentEditable = None
                inputMode = None
                onabort = None
                onblur = None
                oncanplay = None
                oncanplaythrough = None
                onchange = None
                onclick = None
                onclose = None
                oncontextmenu = None
                oncuechange = None
                ondblclick = None
                ondrag = None
                ondragend = None
                ondragenter = None
                ondragleave = None
                ondragover = None
                ondragstart = None
                ondrop = None
                ondurationchange = None
                onemptied = None
                onended = None
                onerror = None
                onfocus = None
                onformdata = None
                oninput = None
                oninvalid = None
                onkeydown = None
                onkeypress = None
                onkeyup = None
                onload = None
                onloadeddata = None
                onloadedmetadata = None
                onloadstart = None
                onmousedown = None
                onmouseenter = None
                onmouseleave = None
                onmousemove = None
                onmouseout = None
                onmouseover = None
                onmouseup = None
                onpause = None
                onplay = None
                onplaying = None
                onprogress = None
                onratechange = None
                onreset = None
                onresize = None
                onscroll = None
                onseeked = None
                onseeking = None
                onselect = None
                onslotchange = None
                onstalled = None
                onsubmit = None
                onsuspend = None
                ontimeupdate = None
                ontoggle = None
                onvolumechange = None
                onwaiting = None
                onwebkitanimationend = None
                onwebkitanimationiteration = None
                onwebkitanimationstart = None
                onwebkittransitionend = None
                onwheel = None
                onmousewheel = None
                onsearch = None
                ontouchcancel = None
                ontouchend = None
                ontouchmove = None
                ontouchstart = None
                ontouchforcechange = None
                onwebkitmouseforcechanged = None
                onwebkitmouseforcedown = None
                onwebkitmouseforcewillbegin = None
                onwebkitmouseforceup = None
                onanimationstart = None
                onanimationiteration = None
                onanimationend = None
                onanimationcancel = None
                ontransitionrun = None
                ontransitionstart = None
                ontransitionend = None
                ontransitioncancel = None
                ongotpointercapture = None
                onlostpointercapture = None
                onpointerdown = None
                onpointermove = None
                onpointerup = None
                onpointercancel = None
                onpointerover = None
                onpointerout = None
                onpointerenter = None
                onpointerleave = None
                onselectstart = None
                onselectionchange = None
                offsetParent = None
                offsetTop = None
                offsetLeft = None
                offsetWidth = None
                offsetHeight = None
                dataset = None
                tabIndex = None
                namespaceURI = None
                prefix = None
                localName = None
                tagName = None
                id = None
                className = None
                classList = None
                slot = None
                part = None
                attributes = None
                shadowRoot = None
                onfocusin = None
                onfocusout = None
                ongesturechange = None
                ongestureend = None
                ongesturestart = None
                onbeforeload = None
                onwebkitneedkey = None
                onwebkitpresentationmodechanged = None
                onwebkitcurrentplaybacktargetiswirelesschanged = None
                onwebkitplaybacktargetavailabilitychanged = None
                role = None
                ariaAtomic = None
                ariaAutoComplete = None
                ariaBusy = None
                ariaChecked = None
                ariaColCount = None
                ariaColIndex = None
                ariaColSpan = None
                ariaCurrent = None
                ariaDisabled = None
                ariaExpanded = None
                ariaHasPopup = None
                ariaHidden = None
                ariaInvalid = None
                ariaKeyShortcuts = None
                ariaLabel = None
                ariaLevel = None
                ariaLive = None
                ariaModal = None
                ariaMultiLine = None
                ariaMultiSelectable = None
                ariaOrientation = None
                ariaPlaceholder = None
                ariaPosInSet = None
                ariaPressed = None
                ariaReadOnly = None
                ariaRelevant = None
                ariaRequired = None
                ariaRoleDescription = None
                ariaRowCount = None
                ariaRowIndex = None
                ariaRowSpan = None
                ariaSelected = None
                ariaSetSize = None
                ariaSort = None
                ariaValueMax = None
                ariaValueMin = None
                ariaValueNow = None
                ariaValueText = None
                scrollTop = None
                scrollLeft = None
                scrollWidth = None
                scrollHeight = None
                clientTop = None
                clientLeft = None
                clientWidth = None
                clientHeight = None
                outerHTML = None
                innerHTML = None
                previousElementSibling = None
                nextElementSibling = None
                children = None
                firstElementChild = None
                lastElementChild = None
                childElementCount = None
                assignedSlot = None
                nodeType = None
                nodeName = None
                baseURI = None
                isConnected = None
                ownerDocument = None
                parentNode = None
                parentElement = None
                childNodes = None
                firstChild = None
                lastChild = None
                previousSibling = None
                nextSibling = None
                nodeValue = None
                textContent = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                addEventListener = None
                after = None
                animate = None
                append = None
                appendChild = None
                attachShadow = None
                before = None
                blur = None
                click = None
                cloneNode = None
                closest = None
                compareDocumentPosition = None
                contains = None
                dispatchEvent = None
                focus = None
                getAnimations = None
                getAttribute = None
                getAttributeNS = None
                getAttributeNames = None
                getAttributeNode = None
                getAttributeNodeNS = None
                getBoundingClientRect = None
                getClientRects = None
                getElementsByClassName = None
                getElementsByTagName = None
                getElementsByTagNameNS = None
                getRootNode = None
                hasAttribute = None
                hasAttributeNS = None
                hasAttributes = None
                hasChildNodes = None
                hasOwnProperty = None
                hasPointerCapture = None
                insertAdjacentElement = None
                insertAdjacentHTML = None
                insertAdjacentText = None
                insertBefore = None
                isDefaultNamespace = None
                isEqualNode = None
                isPrototypeOf = None
                isSameNode = None
                lookupNamespaceURI = None
                lookupPrefix = None
                matches = None
                normalize = None
                prepend = None
                propertyIsEnumerable = None
                querySelector = None
                querySelectorAll = None
                releasePointerCapture = None
                remove = None
                removeAttribute = None
                removeAttributeNS = None
                removeAttributeNode = None
                removeChild = None
                removeEventListener = None
                replaceChild = None
                replaceChildren = None
                replaceWith = None
                scroll = None
                scrollBy = None
                scrollIntoView = None
                scrollIntoViewIfNeeded = None
                scrollTo = None
                setAttribute = None
                setAttributeNS = None
                setAttributeNode = None
                setAttributeNodeNS = None
                setPointerCapture = None
                toLocaleString = None
                toString = None
                toggleAttribute = None
                valueOf = None
                webkitMatchesSelector = None

            childElementCount = None
            rootElement = None

            nodeType = None
            nodeName = None
            baseURI = None
            isConnected = None
            ownerDocument = None

            parentNode = None

            parentElement = None

            class childNodes:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class firstChild:
                version = None
                manifest = None
                title = None
                lang = None
                translate = None
                dir = None
                hidden = None
                accessKey = None
                accessKeyLabel = None
                draggable = None
                spellcheck = None
                autocapitalize = None
                innerText = None
                outerText = None
                autocorrect = None
                webkitdropzone = None
                style = None
                oncopy = None
                oncut = None
                onpaste = None
                onbeforecopy = None
                onbeforecut = None
                onbeforeinput = None
                onbeforepaste = None
                contentEditable = None
                enterKeyHint = None
                isContentEditable = None
                inputMode = None
                onabort = None
                onblur = None
                oncanplay = None
                oncanplaythrough = None
                onchange = None
                onclick = None
                onclose = None
                oncontextmenu = None
                oncuechange = None
                ondblclick = None
                ondrag = None
                ondragend = None
                ondragenter = None
                ondragleave = None
                ondragover = None
                ondragstart = None
                ondrop = None
                ondurationchange = None
                onemptied = None
                onended = None
                onerror = None
                onfocus = None
                onformdata = None
                oninput = None
                oninvalid = None
                onkeydown = None
                onkeypress = None
                onkeyup = None
                onload = None
                onloadeddata = None
                onloadedmetadata = None
                onloadstart = None
                onmousedown = None
                onmouseenter = None
                onmouseleave = None
                onmousemove = None
                onmouseout = None
                onmouseover = None
                onmouseup = None
                onpause = None
                onplay = None
                onplaying = None
                onprogress = None
                onratechange = None
                onreset = None
                onresize = None
                onscroll = None
                onseeked = None
                onseeking = None
                onselect = None
                onslotchange = None
                onstalled = None
                onsubmit = None
                onsuspend = None
                ontimeupdate = None
                ontoggle = None
                onvolumechange = None
                onwaiting = None
                onwebkitanimationend = None
                onwebkitanimationiteration = None
                onwebkitanimationstart = None
                onwebkittransitionend = None
                onwheel = None
                onmousewheel = None
                onsearch = None
                ontouchcancel = None
                ontouchend = None
                ontouchmove = None
                ontouchstart = None
                ontouchforcechange = None
                onwebkitmouseforcechanged = None
                onwebkitmouseforcedown = None
                onwebkitmouseforcewillbegin = None
                onwebkitmouseforceup = None
                onanimationstart = None
                onanimationiteration = None
                onanimationend = None
                onanimationcancel = None
                ontransitionrun = None
                ontransitionstart = None
                ontransitionend = None
                ontransitioncancel = None
                ongotpointercapture = None
                onlostpointercapture = None
                onpointerdown = None
                onpointermove = None
                onpointerup = None
                onpointercancel = None
                onpointerover = None
                onpointerout = None
                onpointerenter = None
                onpointerleave = None
                onselectstart = None
                onselectionchange = None
                offsetParent = None
                offsetTop = None
                offsetLeft = None
                offsetWidth = None
                offsetHeight = None
                dataset = None
                tabIndex = None
                namespaceURI = None
                prefix = None
                localName = None
                tagName = None
                id = None
                className = None
                classList = None
                slot = None
                part = None
                attributes = None
                shadowRoot = None
                onfocusin = None
                onfocusout = None
                ongesturechange = None
                ongestureend = None
                ongesturestart = None
                onbeforeload = None
                onwebkitneedkey = None
                onwebkitpresentationmodechanged = None
                onwebkitcurrentplaybacktargetiswirelesschanged = None
                onwebkitplaybacktargetavailabilitychanged = None
                role = None
                ariaAtomic = None
                ariaAutoComplete = None
                ariaBusy = None
                ariaChecked = None
                ariaColCount = None
                ariaColIndex = None
                ariaColSpan = None
                ariaCurrent = None
                ariaDisabled = None
                ariaExpanded = None
                ariaHasPopup = None
                ariaHidden = None
                ariaInvalid = None
                ariaKeyShortcuts = None
                ariaLabel = None
                ariaLevel = None
                ariaLive = None
                ariaModal = None
                ariaMultiLine = None
                ariaMultiSelectable = None
                ariaOrientation = None
                ariaPlaceholder = None
                ariaPosInSet = None
                ariaPressed = None
                ariaReadOnly = None
                ariaRelevant = None
                ariaRequired = None
                ariaRoleDescription = None
                ariaRowCount = None
                ariaRowIndex = None
                ariaRowSpan = None
                ariaSelected = None
                ariaSetSize = None
                ariaSort = None
                ariaValueMax = None
                ariaValueMin = None
                ariaValueNow = None
                ariaValueText = None
                scrollTop = None
                scrollLeft = None
                scrollWidth = None
                scrollHeight = None
                clientTop = None
                clientLeft = None
                clientWidth = None
                clientHeight = None
                outerHTML = None
                innerHTML = None
                previousElementSibling = None
                nextElementSibling = None
                children = None
                firstElementChild = None
                lastElementChild = None
                childElementCount = None
                assignedSlot = None
                nodeType = None
                nodeName = None
                baseURI = None
                isConnected = None
                ownerDocument = None
                parentNode = None
                parentElement = None
                childNodes = None
                firstChild = None
                lastChild = None
                previousSibling = None
                nextSibling = None
                nodeValue = None
                textContent = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                addEventListener = None
                after = None
                animate = None
                append = None
                appendChild = None
                attachShadow = None
                before = None
                blur = None
                click = None
                cloneNode = None
                closest = None
                compareDocumentPosition = None
                contains = None
                dispatchEvent = None
                focus = None
                getAnimations = None
                getAttribute = None
                getAttributeNS = None
                getAttributeNames = None
                getAttributeNode = None
                getAttributeNodeNS = None
                getBoundingClientRect = None
                getClientRects = None
                getElementsByClassName = None
                getElementsByTagName = None
                getElementsByTagNameNS = None
                getRootNode = None
                hasAttribute = None
                hasAttributeNS = None
                hasAttributes = None
                hasChildNodes = None
                hasOwnProperty = None
                hasPointerCapture = None
                insertAdjacentElement = None
                insertAdjacentHTML = None
                insertAdjacentText = None
                insertBefore = None
                isDefaultNamespace = None
                isEqualNode = None
                isPrototypeOf = None
                isSameNode = None
                lookupNamespaceURI = None
                lookupPrefix = None
                matches = None
                normalize = None
                prepend = None
                propertyIsEnumerable = None
                querySelector = None
                querySelectorAll = None
                releasePointerCapture = None
                remove = None
                removeAttribute = None
                removeAttributeNS = None
                removeAttributeNode = None
                removeChild = None
                removeEventListener = None
                replaceChild = None
                replaceChildren = None
                replaceWith = None
                scroll = None
                scrollBy = None
                scrollIntoView = None
                scrollIntoViewIfNeeded = None
                scrollTo = None
                setAttribute = None
                setAttributeNS = None
                setAttributeNode = None
                setAttributeNodeNS = None
                setPointerCapture = None
                toLocaleString = None
                toString = None
                toggleAttribute = None
                valueOf = None
                webkitMatchesSelector = None

            class lastChild:
                version = None
                manifest = None
                title = None
                lang = None
                translate = None
                dir = None
                hidden = None
                accessKey = None
                accessKeyLabel = None
                draggable = None
                spellcheck = None
                autocapitalize = None
                innerText = None
                outerText = None
                autocorrect = None
                webkitdropzone = None
                style = None
                oncopy = None
                oncut = None
                onpaste = None
                onbeforecopy = None
                onbeforecut = None
                onbeforeinput = None
                onbeforepaste = None
                contentEditable = None
                enterKeyHint = None
                isContentEditable = None
                inputMode = None
                onabort = None
                onblur = None
                oncanplay = None
                oncanplaythrough = None
                onchange = None
                onclick = None
                onclose = None
                oncontextmenu = None
                oncuechange = None
                ondblclick = None
                ondrag = None
                ondragend = None
                ondragenter = None
                ondragleave = None
                ondragover = None
                ondragstart = None
                ondrop = None
                ondurationchange = None
                onemptied = None
                onended = None
                onerror = None
                onfocus = None
                onformdata = None
                oninput = None
                oninvalid = None
                onkeydown = None
                onkeypress = None
                onkeyup = None
                onload = None
                onloadeddata = None
                onloadedmetadata = None
                onloadstart = None
                onmousedown = None
                onmouseenter = None
                onmouseleave = None
                onmousemove = None
                onmouseout = None
                onmouseover = None
                onmouseup = None
                onpause = None
                onplay = None
                onplaying = None
                onprogress = None
                onratechange = None
                onreset = None
                onresize = None
                onscroll = None
                onseeked = None
                onseeking = None
                onselect = None
                onslotchange = None
                onstalled = None
                onsubmit = None
                onsuspend = None
                ontimeupdate = None
                ontoggle = None
                onvolumechange = None
                onwaiting = None
                onwebkitanimationend = None
                onwebkitanimationiteration = None
                onwebkitanimationstart = None
                onwebkittransitionend = None
                onwheel = None
                onmousewheel = None
                onsearch = None
                ontouchcancel = None
                ontouchend = None
                ontouchmove = None
                ontouchstart = None
                ontouchforcechange = None
                onwebkitmouseforcechanged = None
                onwebkitmouseforcedown = None
                onwebkitmouseforcewillbegin = None
                onwebkitmouseforceup = None
                onanimationstart = None
                onanimationiteration = None
                onanimationend = None
                onanimationcancel = None
                ontransitionrun = None
                ontransitionstart = None
                ontransitionend = None
                ontransitioncancel = None
                ongotpointercapture = None
                onlostpointercapture = None
                onpointerdown = None
                onpointermove = None
                onpointerup = None
                onpointercancel = None
                onpointerover = None
                onpointerout = None
                onpointerenter = None
                onpointerleave = None
                onselectstart = None
                onselectionchange = None
                offsetParent = None
                offsetTop = None
                offsetLeft = None
                offsetWidth = None
                offsetHeight = None
                dataset = None
                tabIndex = None
                namespaceURI = None
                prefix = None
                localName = None
                tagName = None
                id = None
                className = None
                classList = None
                slot = None
                part = None
                attributes = None
                shadowRoot = None
                onfocusin = None
                onfocusout = None
                ongesturechange = None
                ongestureend = None
                ongesturestart = None
                onbeforeload = None
                onwebkitneedkey = None
                onwebkitpresentationmodechanged = None
                onwebkitcurrentplaybacktargetiswirelesschanged = None
                onwebkitplaybacktargetavailabilitychanged = None
                role = None
                ariaAtomic = None
                ariaAutoComplete = None
                ariaBusy = None
                ariaChecked = None
                ariaColCount = None
                ariaColIndex = None
                ariaColSpan = None
                ariaCurrent = None
                ariaDisabled = None
                ariaExpanded = None
                ariaHasPopup = None
                ariaHidden = None
                ariaInvalid = None
                ariaKeyShortcuts = None
                ariaLabel = None
                ariaLevel = None
                ariaLive = None
                ariaModal = None
                ariaMultiLine = None
                ariaMultiSelectable = None
                ariaOrientation = None
                ariaPlaceholder = None
                ariaPosInSet = None
                ariaPressed = None
                ariaReadOnly = None
                ariaRelevant = None
                ariaRequired = None
                ariaRoleDescription = None
                ariaRowCount = None
                ariaRowIndex = None
                ariaRowSpan = None
                ariaSelected = None
                ariaSetSize = None
                ariaSort = None
                ariaValueMax = None
                ariaValueMin = None
                ariaValueNow = None
                ariaValueText = None
                scrollTop = None
                scrollLeft = None
                scrollWidth = None
                scrollHeight = None
                clientTop = None
                clientLeft = None
                clientWidth = None
                clientHeight = None
                outerHTML = None
                innerHTML = None
                previousElementSibling = None
                nextElementSibling = None
                children = None
                firstElementChild = None
                lastElementChild = None
                childElementCount = None
                assignedSlot = None
                nodeType = None
                nodeName = None
                baseURI = None
                isConnected = None
                ownerDocument = None
                parentNode = None
                parentElement = None
                childNodes = None
                firstChild = None
                lastChild = None
                previousSibling = None
                nextSibling = None
                nodeValue = None
                textContent = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                addEventListener = None
                after = None
                animate = None
                append = None
                appendChild = None
                attachShadow = None
                before = None
                blur = None
                click = None
                cloneNode = None
                closest = None
                compareDocumentPosition = None
                contains = None
                dispatchEvent = None
                focus = None
                getAnimations = None
                getAttribute = None
                getAttributeNS = None
                getAttributeNames = None
                getAttributeNode = None
                getAttributeNodeNS = None
                getBoundingClientRect = None
                getClientRects = None
                getElementsByClassName = None
                getElementsByTagName = None
                getElementsByTagNameNS = None
                getRootNode = None
                hasAttribute = None
                hasAttributeNS = None
                hasAttributes = None
                hasChildNodes = None
                hasOwnProperty = None
                hasPointerCapture = None
                insertAdjacentElement = None
                insertAdjacentHTML = None
                insertAdjacentText = None
                insertBefore = None
                isDefaultNamespace = None
                isEqualNode = None
                isPrototypeOf = None
                isSameNode = None
                lookupNamespaceURI = None
                lookupPrefix = None
                matches = None
                normalize = None
                prepend = None
                propertyIsEnumerable = None
                querySelector = None
                querySelectorAll = None
                releasePointerCapture = None
                remove = None
                removeAttribute = None
                removeAttributeNS = None
                removeAttributeNode = None
                removeChild = None
                removeEventListener = None
                replaceChild = None
                replaceChildren = None
                replaceWith = None
                scroll = None
                scrollBy = None
                scrollIntoView = None
                scrollIntoViewIfNeeded = None
                scrollTo = None
                setAttribute = None
                setAttributeNS = None
                setAttributeNode = None
                setAttributeNodeNS = None
                setPointerCapture = None
                toLocaleString = None
                toString = None
                toggleAttribute = None
                valueOf = None
                webkitMatchesSelector = None

            previousSibling = None

            nextSibling = None

            nodeValue = None

            textContent = None

            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            addEventListener = None

            adoptNode = None

            append = None

            appendChild = None

            captureEvents = None

            caretRangeFromPoint = None

            clear = None

            cloneNode = None

            close = None

            compareDocumentPosition = None

            contains = None

            createAttribute = None

            createAttributeNS = None

            createCDATASection = None

            createComment = None

            createDocumentFragment = None

            createElement = None

            createElementNS = None

            createEvent = None

            createExpression = None

            createNSResolver = None

            createNodeIterator = None

            createProcessingInstruction = None

            createRange = None

            createTextNode = None

            createTouch = None

            createTouchList = None

            createTreeWalker = None

            dispatchEvent = None

            elementFromPoint = None

            elementsFromPoint = None

            evaluate = None

            execCommand = None

            exitPictureInPicture = None

            getAnimations = None

            getCSSCanvasContext = None

            getElementById = None

            getElementsByClassName = None

            getElementsByName = None

            getElementsByTagName = None

            getElementsByTagNameNS = None

            getOverrideStyle = None

            getRootNode = None

            getSelection = None

            hasChildNodes = None

            hasFocus = None

            hasOwnProperty = None

            hasStorageAccess = None

            importNode = None

            insertBefore = None

            isDefaultNamespace = None

            isEqualNode = None

            isPrototypeOf = None

            isSameNode = None

            lookupNamespaceURI = None

            lookupPrefix = None

            normalize = None

            open = None

            prepend = None

            propertyIsEnumerable = None

            queryCommandEnabled = None

            queryCommandIndeterm = None

            queryCommandState = None

            queryCommandSupported = None

            queryCommandValue = None

            querySelector = None

            querySelectorAll = None

            releaseEvents = None

            removeChild = None

            removeEventListener = None

            replaceChild = None

            replaceChildren = None

            requestStorageAccess = None

            toLocaleString = None

            toString = None

            valueOf = None

            write = None

            writeln = None


        name = None
        class location:
            href = None
            protocol = None
            host = None
            hostname = None
            port = None
            pathname = None
            search = None
            hash = None
            origin = None
            class ancestorOrigins:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            assign = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            reload = None

            replace = None

            toLocaleString = None

            toString = None

            valueOf = None


        class history:
            length = None
            scrollRestoration = None
            state = None

            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            back = None

            forward = None

            go = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            pushState = None

            replaceState = None

            toLocaleString = None

            toString = None

            valueOf = None


        class customElements:
            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            createDocument = None

            createDocumentType = None

            createHTMLDocument = None

            hasFeature = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        class locationbar:
            visible = None
            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        class menubar:
            visible = None
            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        class personalbar:
            visible = None
            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        class scrollbars:
            visible = None
            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        class statusbar:
            visible = None
            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        class toolbar:
            visible = None
            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        status = None
        closed = None
        length = None
        opener = None

        frameElement = None

        class navigator:
            standalone = None
            class clipboard:
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                createDocument = None
                createDocumentType = None
                createHTMLDocument = None
                hasFeature = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class geolocation:
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                createDocument = None
                createDocumentType = None
                createHTMLDocument = None
                hasFeature = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class mediaCapabilities:
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                createDocument = None
                createDocumentType = None
                createHTMLDocument = None
                hasFeature = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class mediaSession:
                metadata = None
                playbackState = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                callActionHandler = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                setActionHandler = None
                setPositionState = None
                toLocaleString = None
                toString = None
                valueOf = None

            class mediaDevices:
                ondevicechange = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                addEventListener = None
                dispatchEvent = None
                enumerateDevices = None
                getSupportedConstraints = None
                getUserMedia = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                removeEventListener = None
                toLocaleString = None
                toString = None
                valueOf = None

            webdriver = None
            maxTouchPoints = None
            cookieEnabled = None
            appCodeName = None
            appName = None
            appVersion = None
            platform = None
            product = None
            productSub = None
            userAgent = None
            vendor = None
            vendorSub = None
            language = None
            languages = None
            onLine = None
            class plugins:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class mimeTypes:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            canShare = None

            getGamepads = None

            getStorageUpdates = None

            hasOwnProperty = None

            isPrototypeOf = None

            javaEnabled = None

            propertyIsEnumerable = None

            requestMediaKeySystemAccess = None

            sendBeacon = None

            share = None

            toLocaleString = None

            toString = None

            valueOf = None


        class applicationCache:
            status = None
            onchecking = None

            onerror = None

            onnoupdate = None

            ondownloading = None

            onprogress = None

            onupdateready = None

            oncached = None

            onobsolete = None

            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            abort = None

            addEventListener = None

            dispatchEvent = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            removeEventListener = None

            swapCache = None

            toLocaleString = None

            toString = None

            update = None

            valueOf = None


        event = None

        defaultStatus = None
        defaultstatus = None
        offscreenBuffering = None
        class clientInformation:
            standalone = None
            class clipboard:
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                createDocument = None
                createDocumentType = None
                createHTMLDocument = None
                hasFeature = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class geolocation:
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                createDocument = None
                createDocumentType = None
                createHTMLDocument = None
                hasFeature = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class mediaCapabilities:
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                createDocument = None
                createDocumentType = None
                createHTMLDocument = None
                hasFeature = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class mediaSession:
                metadata = None
                playbackState = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                callActionHandler = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                setActionHandler = None
                setPositionState = None
                toLocaleString = None
                toString = None
                valueOf = None

            class mediaDevices:
                ondevicechange = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                addEventListener = None
                dispatchEvent = None
                enumerateDevices = None
                getSupportedConstraints = None
                getUserMedia = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                removeEventListener = None
                toLocaleString = None
                toString = None
                valueOf = None

            webdriver = None
            maxTouchPoints = None
            cookieEnabled = None
            appCodeName = None
            appName = None
            appVersion = None
            platform = None
            product = None
            productSub = None
            userAgent = None
            vendor = None
            vendorSub = None
            language = None
            languages = None
            onLine = None
            class plugins:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            class mimeTypes:
                length = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                contains = None
                hasOwnProperty = None
                isPrototypeOf = None
                item = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            canShare = None

            getGamepads = None

            getStorageUpdates = None

            hasOwnProperty = None

            isPrototypeOf = None

            javaEnabled = None

            propertyIsEnumerable = None

            requestMediaKeySystemAccess = None

            sendBeacon = None

            share = None

            toLocaleString = None

            toString = None

            valueOf = None


        ongesturechange = None

        ongestureend = None

        ongesturestart = None

        class speechSynthesis:
            pending = None
            speaking = None
            paused = None
            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            cancel = None

            getVoices = None

            hasOwnProperty = None

            isPrototypeOf = None

            pause = None

            propertyIsEnumerable = None

            resume = None

            speak = None

            toLocaleString = None

            toString = None

            valueOf = None


        onabort = None

        onblur = None

        oncanplay = None

        oncanplaythrough = None

        onchange = None

        onclick = None

        onclose = None

        oncontextmenu = None

        oncuechange = None

        ondblclick = None

        ondrag = None

        ondragend = None

        ondragenter = None

        ondragleave = None

        ondragover = None

        ondragstart = None

        ondrop = None

        ondurationchange = None

        onemptied = None

        onended = None

        onerror = None

        onfocus = None

        onformdata = None

        oninput = None

        oninvalid = None

        onkeydown = None

        onkeypress = None

        onkeyup = None

        onload = None

        onloadeddata = None

        onloadedmetadata = None

        onloadstart = None

        onmousedown = None

        onmouseenter = None

        onmouseleave = None

        onmousemove = None

        onmouseout = None

        onmouseover = None

        onmouseup = None

        onpause = None

        onplay = None

        onplaying = None

        onprogress = None

        onratechange = None

        onreset = None

        onresize = None

        onscroll = None

        onseeked = None

        onseeking = None

        onselect = None

        onslotchange = None

        onstalled = None

        onsubmit = None

        onsuspend = None

        ontimeupdate = None

        ontoggle = None

        onvolumechange = None

        onwaiting = None

        onwebkitanimationend = None

        onwebkitanimationiteration = None

        onwebkitanimationstart = None

        onwebkittransitionend = None

        onwheel = None

        onmousewheel = None

        onsearch = None

        onwebkitmouseforcechanged = None

        onwebkitmouseforcedown = None

        onwebkitmouseforcewillbegin = None

        onwebkitmouseforceup = None

        onanimationstart = None

        onanimationiteration = None

        onanimationend = None

        onanimationcancel = None

        ontransitionrun = None

        ontransitionstart = None

        ontransitionend = None

        ontransitioncancel = None

        ongotpointercapture = None

        onlostpointercapture = None

        onpointerdown = None

        onpointermove = None

        onpointerup = None

        onpointercancel = None

        onpointerover = None

        onpointerout = None

        onpointerenter = None

        onpointerleave = None

        onselectstart = None

        onselectionchange = None

        class screen:
            height = None
            width = None
            colorDepth = None
            pixelDepth = None
            availLeft = None
            availTop = None
            availHeight = None
            availWidth = None
            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        innerWidth = None
        innerHeight = None
        scrollX = None
        pageXOffset = None
        scrollY = None
        pageYOffset = None
        screenX = None
        screenLeft = None
        screenY = None
        screenTop = None
        outerWidth = None
        outerHeight = None
        devicePixelRatio = None
        class styleMedia:
            type = None
            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            hasOwnProperty = None

            isPrototypeOf = None

            matchMedium = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        orientation = None
        onorientationchange = None

        ondevicemotion = None

        ondeviceorientation = None

        onafterprint = None

        onbeforeprint = None

        onbeforeunload = None

        onhashchange = None

        onlanguagechange = None

        onmessage = None

        onoffline = None

        ononline = None

        onpagehide = None

        onpageshow = None

        onpopstate = None

        onrejectionhandled = None

        onstorage = None

        onunhandledrejection = None

        onunload = None

        class localStorage:
            length = None

            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            contains = None

            hasOwnProperty = None

            isPrototypeOf = None

            item = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        origin = None
        isSecureContext = None
        class indexedDB:
            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            createDocument = None

            createDocumentType = None

            createHTMLDocument = None

            hasFeature = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        class webkitIndexedDB:
            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            createDocument = None

            createDocumentType = None

            createHTMLDocument = None

            hasFeature = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        class crypto:
            class subtle:
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                createDocument = None
                createDocumentType = None
                createHTMLDocument = None
                hasFeature = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                toLocaleString = None
                toString = None
                valueOf = None

            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            getRandomValues = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        class performance:
            timeOrigin = None
            class navigation:
                type = None
                redirectCount = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                toJSON = None
                toLocaleString = None
                toString = None
                valueOf = None

            class timing:
                navigationStart = None
                unloadEventStart = None
                unloadEventEnd = None
                redirectStart = None
                redirectEnd = None
                fetchStart = None
                domainLookupStart = None
                domainLookupEnd = None
                connectStart = None
                connectEnd = None
                secureConnectionStart = None
                requestStart = None
                responseStart = None
                responseEnd = None
                domLoading = None
                domInteractive = None
                domContentLoadedEventStart = None
                domContentLoadedEventEnd = None
                domComplete = None
                loadEventStart = None
                loadEventEnd = None
                __defineGetter__ = None
                __defineSetter__ = None
                __lookupGetter__ = None
                __lookupSetter__ = None
                hasOwnProperty = None
                isPrototypeOf = None
                propertyIsEnumerable = None
                toJSON = None
                toLocaleString = None
                toString = None
                valueOf = None

            onresourcetimingbufferfull = None

            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            addEventListener = None

            clearMarks = None

            clearMeasures = None

            clearResourceTimings = None

            dispatchEvent = None

            getEntries = None

            getEntriesByName = None

            getEntriesByType = None

            hasOwnProperty = None

            isPrototypeOf = None

            mark = None

            measure = None

            now = None

            propertyIsEnumerable = None

            removeEventListener = None

            setResourceTimingBufferSize = None

            toJSON = None

            toLocaleString = None

            toString = None

            valueOf = None


        class sessionStorage:
            length = None

            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            contains = None

            hasOwnProperty = None

            isPrototypeOf = None

            item = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        ontouchcancel = None

        ontouchend = None

        ontouchmove = None

        ontouchstart = None

        ontouchforcechange = None

        class visualViewport:
            offsetLeft = None
            offsetTop = None
            pageLeft = None
            pageTop = None
            width = None
            height = None
            scale = None
            onresize = None

            onscroll = None

            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            addEventListener = None

            dispatchEvent = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            removeEventListener = None

            toLocaleString = None

            toString = None

            valueOf = None


        class caches:
            __defineGetter__ = None

            __defineSetter__ = None

            __lookupGetter__ = None

            __lookupSetter__ = None

            createDocument = None

            createDocumentType = None

            createHTMLDocument = None

            hasFeature = None

            hasOwnProperty = None

            isPrototypeOf = None

            propertyIsEnumerable = None

            toLocaleString = None

            toString = None

            valueOf = None


        AbortController = None

        AbortSignal = None

        AbstractRange = None

        AggregateError = None

        AnalyserNode = None

        Animation = None

        AnimationEffect = None

        AnimationEvent = None

        AnimationPlaybackEvent = None

        AnimationTimeline = None

        ApplePayError = None

        ApplePaySession = None

        ApplePaySetup = None

        ApplePaySetupFeature = None

        ApplicationCache = None

        Array = None

        ArrayBuffer = None

        Attr = None

        Audio = None

        AudioBuffer = None

        AudioBufferSourceNode = None

        AudioContext = None

        AudioDestinationNode = None

        AudioListener = None

        AudioNode = None

        AudioParam = None

        AudioParamMap = None

        AudioProcessingEvent = None

        AudioScheduledSourceNode = None

        AudioTrack = None

        AudioTrackList = None

        AudioWorklet = None

        AudioWorkletNode = None

        BarProp = None

        BaseAudioContext = None

        BeforeUnloadEvent = None

        BigInt = None

        BigInt64Array = None

        BigUint64Array = None

        BiquadFilterNode = None

        Blob = None

        BlobEvent = None

        Boolean = None

        ByteLengthQueuingStrategy = None

        CDATASection = None

        CSSAnimation = None

        CSSConditionRule = None

        CSSFontFaceRule = None

        CSSGroupingRule = None

        CSSImportRule = None

        CSSKeyframeRule = None

        CSSKeyframesRule = None

        CSSMediaRule = None

        CSSNamespaceRule = None

        CSSPageRule = None

        CSSPrimitiveValue = None

        CSSRule = None

        CSSRuleList = None

        CSSStyleDeclaration = None

        CSSStyleRule = None

        CSSStyleSheet = None

        CSSSupportsRule = None

        CSSTransition = None

        CSSValue = None

        CSSValueList = None

        Cache = None

        CacheStorage = None

        CanvasCaptureMediaStreamTrack = None

        CanvasGradient = None

        CanvasPattern = None

        CanvasRenderingContext2D = None

        ChannelMergerNode = None

        ChannelSplitterNode = None

        CharacterData = None

        Clipboard = None

        ClipboardEvent = None

        ClipboardItem = None

        CloseEvent = None

        Comment = None

        CompositionEvent = None

        ConstantSourceNode = None

        ConvolverNode = None

        CountQueuingStrategy = None

        Counter = None

        Crypto = None

        CryptoKey = None

        CustomElementRegistry = None

        CustomEvent = None

        DOMException = None

        DOMImplementation = None

        DOMMatrix = None

        DOMMatrixReadOnly = None

        DOMParser = None

        DOMPoint = None

        DOMPointReadOnly = None

        DOMQuad = None

        DOMRect = None

        DOMRectList = None

        DOMRectReadOnly = None

        DOMStringList = None

        DOMStringMap = None

        DOMTokenList = None

        DataCue = None

        DataTransfer = None

        DataTransferItem = None

        DataTransferItemList = None

        DataView = None

        Date = None

        DelayNode = None

        DeviceMotionEvent = None

        DeviceOrientationEvent = None

        Document = None

        DocumentFragment = None

        DocumentTimeline = None

        DocumentType = None

        DragEvent = None

        DynamicsCompressorNode = None

        Element = None

        EnterPictureInPictureEvent = None

        Error = None

        ErrorEvent = None

        EvalError = None

        Event = None

        EventSource = None

        EventTarget = None

        File = None

        FileList = None

        FileReader = None

        FileSystem = None

        FileSystemDirectoryEntry = None

        FileSystemDirectoryReader = None

        FileSystemEntry = None

        FileSystemFileEntry = None

        FinalizationRegistry = None

        Float32Array = None

        Float64Array = None

        FocusEvent = None

        FontFace = None

        FontFaceSet = None

        FormData = None

        FormDataEvent = None

        Function = None

        GainNode = None

        Gamepad = None

        GamepadButton = None

        GamepadEvent = None

        Geolocation = None

        GeolocationCoordinates = None

        GeolocationPosition = None

        GeolocationPositionError = None

        GestureEvent = None

        HTMLAllCollection = None

        HTMLAnchorElement = None

        HTMLAreaElement = None

        HTMLAudioElement = None

        HTMLBRElement = None

        HTMLBaseElement = None

        HTMLBodyElement = None

        HTMLButtonElement = None

        HTMLCanvasElement = None

        HTMLCollection = None

        HTMLDListElement = None

        HTMLDataElement = None

        HTMLDataListElement = None

        HTMLDetailsElement = None

        HTMLDirectoryElement = None

        HTMLDivElement = None

        HTMLDocument = None

        HTMLElement = None

        HTMLEmbedElement = None

        HTMLFieldSetElement = None

        HTMLFontElement = None

        HTMLFormControlsCollection = None

        HTMLFormElement = None

        HTMLFrameElement = None

        HTMLFrameSetElement = None

        HTMLHRElement = None

        HTMLHeadElement = None

        HTMLHeadingElement = None

        HTMLHtmlElement = None

        HTMLIFrameElement = None

        HTMLImageElement = None

        HTMLInputElement = None

        HTMLLIElement = None

        HTMLLabelElement = None

        HTMLLegendElement = None

        HTMLLinkElement = None

        HTMLMapElement = None

        HTMLMarqueeElement = None

        HTMLMediaElement = None

        HTMLMenuElement = None

        HTMLMetaElement = None

        HTMLMeterElement = None

        HTMLModElement = None

        HTMLOListElement = None

        HTMLObjectElement = None

        HTMLOptGroupElement = None

        HTMLOptionElement = None

        HTMLOptionsCollection = None

        HTMLOutputElement = None

        HTMLParagraphElement = None

        HTMLParamElement = None

        HTMLPictureElement = None

        HTMLPreElement = None

        HTMLProgressElement = None

        HTMLQuoteElement = None

        HTMLScriptElement = None

        HTMLSelectElement = None

        HTMLSlotElement = None

        HTMLSourceElement = None

        HTMLSpanElement = None

        HTMLStyleElement = None

        HTMLTableCaptionElement = None

        HTMLTableCellElement = None

        HTMLTableColElement = None

        HTMLTableElement = None

        HTMLTableRowElement = None

        HTMLTableSectionElement = None

        HTMLTemplateElement = None

        HTMLTextAreaElement = None

        HTMLTimeElement = None

        HTMLTitleElement = None

        HTMLTrackElement = None

        HTMLUListElement = None

        HTMLUnknownElement = None

        HTMLVideoElement = None

        HashChangeEvent = None

        Headers = None

        History = None

        IDBCursor = None

        IDBCursorWithValue = None

        IDBDatabase = None

        IDBFactory = None

        IDBIndex = None

        IDBKeyRange = None

        IDBObjectStore = None

        IDBOpenDBRequest = None

        IDBRequest = None

        IDBTransaction = None

        IDBVersionChangeEvent = None

        IIRFilterNode = None

        Image = None

        ImageBitmap = None

        ImageBitmapRenderingContext = None

        ImageData = None

        InputEvent = None

        Int16Array = None

        Int32Array = None

        Int8Array = None

        IntersectionObserver = None

        IntersectionObserverEntry = None

        KeyboardEvent = None

        KeyframeEffect = None

        Location = None

        Map = None

        MathMLElement = None

        MathMLMathElement = None

        MediaCapabilities = None

        MediaController = None

        MediaDeviceInfo = None

        MediaDevices = None

        MediaElementAudioSourceNode = None

        MediaEncryptedEvent = None

        MediaError = None

        MediaKeyMessageEvent = None

        MediaKeySession = None

        MediaKeyStatusMap = None

        MediaKeySystemAccess = None

        MediaKeys = None

        MediaList = None

        MediaMetadata = None

        MediaQueryList = None

        MediaQueryListEvent = None

        MediaRecorder = None

        MediaRecorderErrorEvent = None

        MediaSession = None

        MediaSource = None

        MediaStream = None

        MediaStreamAudioDestinationNode = None

        MediaStreamAudioSourceNode = None

        MediaStreamTrack = None

        MediaStreamTrackEvent = None

        MerchantValidationEvent = None

        MessageChannel = None

        MessageEvent = None

        MessagePort = None

        MimeType = None

        MimeTypeArray = None

        MouseEvent = None

        MutationEvent = None

        MutationObserver = None

        MutationRecord = None

        NamedNodeMap = None

        Navigator = None

        Node = None

        NodeFilter = None

        NodeIterator = None

        NodeList = None

        Number = None

        Object = None

        OfflineAudioCompletionEvent = None

        OfflineAudioContext = None

        Option = None

        OscillatorNode = None

        OverconstrainedError = None

        OverconstrainedErrorEvent = None

        OverflowEvent = None

        PageTransitionEvent = None

        PannerNode = None

        Path2D = None

        PaymentAddress = None

        PaymentMethodChangeEvent = None

        PaymentRequest = None

        PaymentRequestUpdateEvent = None

        PaymentResponse = None

        Performance = None

        PerformanceEntry = None

        PerformanceMark = None

        PerformanceMeasure = None

        PerformanceNavigation = None

        PerformanceObserver = None

        PerformanceObserverEntryList = None

        PerformancePaintTiming = None

        PerformanceResourceTiming = None

        PerformanceTiming = None

        PeriodicWave = None

        PictureInPictureWindow = None

        Plugin = None

        PluginArray = None

        PointerEvent = None

        PopStateEvent = None

        ProcessingInstruction = None

        ProgressEvent = None

        Promise = None

        PromiseRejectionEvent = None

        Proxy = None

        RGBColor = None

        RTCCertificate = None

        RTCDTMFSender = None

        RTCDTMFToneChangeEvent = None

        RTCDataChannel = None

        RTCDataChannelEvent = None

        RTCIceCandidate = None

        RTCIceTransport = None

        RTCPeerConnection = None

        RTCPeerConnectionIceErrorEvent = None

        RTCPeerConnectionIceEvent = None

        RTCRtpReceiver = None

        RTCRtpSender = None

        RTCRtpTransceiver = None

        RTCSessionDescription = None

        RTCStatsReport = None

        RTCTrackEvent = None

        RadioNodeList = None

        Range = None

        RangeError = None

        ReadableStream = None

        Rect = None

        ReferenceError = None

        RegExp = None

        RemotePlayback = None

        Request = None

        ResizeObserver = None

        ResizeObserverEntry = None

        Response = None

        SQLTransaction = None

        SVGAElement = None

        SVGAltGlyphDefElement = None

        SVGAltGlyphElement = None

        SVGAltGlyphItemElement = None

        SVGAngle = None

        SVGAnimateColorElement = None

        SVGAnimateElement = None

        SVGAnimateMotionElement = None

        SVGAnimateTransformElement = None

        SVGAnimatedAngle = None

        SVGAnimatedBoolean = None

        SVGAnimatedEnumeration = None

        SVGAnimatedInteger = None

        SVGAnimatedLength = None

        SVGAnimatedLengthList = None

        SVGAnimatedNumber = None

        SVGAnimatedNumberList = None

        SVGAnimatedPreserveAspectRatio = None

        SVGAnimatedRect = None

        SVGAnimatedString = None

        SVGAnimatedTransformList = None

        SVGAnimationElement = None

        SVGCircleElement = None

        SVGClipPathElement = None

        SVGComponentTransferFunctionElement = None

        SVGCursorElement = None

        SVGDefsElement = None

        SVGDescElement = None

        SVGDocument = None

        SVGElement = None

        SVGEllipseElement = None

        SVGFEBlendElement = None

        SVGFEColorMatrixElement = None

        SVGFEComponentTransferElement = None

        SVGFECompositeElement = None

        SVGFEConvolveMatrixElement = None

        SVGFEDiffuseLightingElement = None

        SVGFEDisplacementMapElement = None

        SVGFEDistantLightElement = None

        SVGFEDropShadowElement = None

        SVGFEFloodElement = None

        SVGFEFuncAElement = None

        SVGFEFuncBElement = None

        SVGFEFuncGElement = None

        SVGFEFuncRElement = None

        SVGFEGaussianBlurElement = None

        SVGFEImageElement = None

        SVGFEMergeElement = None

        SVGFEMergeNodeElement = None

        SVGFEMorphologyElement = None

        SVGFEOffsetElement = None

        SVGFEPointLightElement = None

        SVGFESpecularLightingElement = None

        SVGFESpotLightElement = None

        SVGFETileElement = None

        SVGFETurbulenceElement = None

        SVGFilterElement = None

        SVGFontElement = None

        SVGFontFaceElement = None

        SVGFontFaceFormatElement = None

        SVGFontFaceNameElement = None

        SVGFontFaceSrcElement = None

        SVGFontFaceUriElement = None

        SVGForeignObjectElement = None

        SVGGElement = None

        SVGGeometryElement = None

        SVGGlyphElement = None

        SVGGlyphRefElement = None

        SVGGradientElement = None

        SVGGraphicsElement = None

        SVGHKernElement = None

        SVGImageElement = None

        SVGLength = None

        SVGLengthList = None

        SVGLineElement = None

        SVGLinearGradientElement = None

        SVGMPathElement = None

        SVGMarkerElement = None

        SVGMaskElement = None

        SVGMatrix = None

        SVGMetadataElement = None

        SVGMissingGlyphElement = None

        SVGNumber = None

        SVGNumberList = None

        SVGPathElement = None

        SVGPathSeg = None

        SVGPathSegArcAbs = None

        SVGPathSegArcRel = None

        SVGPathSegClosePath = None

        SVGPathSegCurvetoCubicAbs = None

        SVGPathSegCurvetoCubicRel = None

        SVGPathSegCurvetoCubicSmoothAbs = None

        SVGPathSegCurvetoCubicSmoothRel = None

        SVGPathSegCurvetoQuadraticAbs = None

        SVGPathSegCurvetoQuadraticRel = None

        SVGPathSegCurvetoQuadraticSmoothAbs = None

        SVGPathSegCurvetoQuadraticSmoothRel = None

        SVGPathSegLinetoAbs = None

        SVGPathSegLinetoHorizontalAbs = None

        SVGPathSegLinetoHorizontalRel = None

        SVGPathSegLinetoRel = None

        SVGPathSegLinetoVerticalAbs = None

        SVGPathSegLinetoVerticalRel = None

        SVGPathSegList = None

        SVGPathSegMovetoAbs = None

        SVGPathSegMovetoRel = None

        SVGPatternElement = None

        SVGPoint = None

        SVGPointList = None

        SVGPolygonElement = None

        SVGPolylineElement = None

        SVGPreserveAspectRatio = None

        SVGRadialGradientElement = None

        SVGRect = None

        SVGRectElement = None

        SVGRenderingIntent = None

        SVGSVGElement = None

        SVGScriptElement = None

        SVGSetElement = None

        SVGStopElement = None

        SVGStringList = None

        SVGStyleElement = None

        SVGSwitchElement = None

        SVGSymbolElement = None

        SVGTRefElement = None

        SVGTSpanElement = None

        SVGTextContentElement = None

        SVGTextElement = None

        SVGTextPathElement = None

        SVGTextPositioningElement = None

        SVGTitleElement = None

        SVGTransform = None

        SVGTransformList = None

        SVGUnitTypes = None

        SVGUseElement = None

        SVGVKernElement = None

        SVGViewElement = None

        SVGViewSpec = None

        SVGZoomEvent = None

        Screen = None

        ScriptProcessorNode = None

        SecurityPolicyViolationEvent = None

        Selection = None

        Set = None

        ShadowRoot = None

        SourceBuffer = None

        SourceBufferList = None

        SpeechRecognitionAlternative = None

        SpeechRecognitionErrorEvent = None

        SpeechRecognitionEvent = None

        SpeechRecognitionResult = None

        SpeechRecognitionResultList = None

        SpeechSynthesisEvent = None

        SpeechSynthesisUtterance = None

        StaticRange = None

        StereoPannerNode = None

        Storage = None

        StorageEvent = None

        String = None

        StyleSheet = None

        StyleSheetList = None

        SubmitEvent = None

        SubtleCrypto = None

        Symbol = None

        SyntaxError = None

        Text = None

        TextDecoder = None

        TextDecoderStream = None

        TextEncoder = None

        TextEncoderStream = None

        TextEvent = None

        TextMetrics = None

        TextTrack = None

        TextTrackCue = None

        TextTrackCueList = None

        TextTrackList = None

        TimeRanges = None

        Touch = None

        TouchEvent = None

        TouchList = None

        TrackEvent = None

        TransformStream = None

        TransformStreamDefaultController = None

        TransitionEvent = None

        TreeWalker = None

        TypeError = None

        UIEvent = None

        URIError = None

        URL = None

        URLSearchParams = None

        Uint16Array = None

        Uint32Array = None

        Uint8Array = None

        Uint8ClampedArray = None

        UserMessageHandler = None

        UserMessageHandlersNamespace = None

        VTTCue = None

        VTTRegion = None

        ValidityState = None

        VideoTrack = None

        VideoTrackList = None

        VisualViewport = None

        WaveShaperNode = None

        WeakMap = None

        WeakRef = None

        WeakSet = None

        WebGL2RenderingContext = None

        WebGLActiveInfo = None

        WebGLBuffer = None

        WebGLContextEvent = None

        WebGLFramebuffer = None

        WebGLProgram = None

        WebGLQuery = None

        WebGLRenderbuffer = None

        WebGLRenderingContext = None

        WebGLSampler = None

        WebGLShader = None

        WebGLShaderPrecisionFormat = None

        WebGLSync = None

        WebGLTexture = None

        WebGLTransformFeedback = None

        WebGLUniformLocation = None

        WebGLVertexArrayObject = None

        WebKitAnimationEvent = None

        WebKitCSSMatrix = None

        WebKitMediaKeyError = None

        WebKitMediaKeyMessageEvent = None

        WebKitMediaKeyNeededEvent = None

        WebKitMediaKeySession = None

        WebKitMediaKeys = None

        WebKitMutationObserver = None

        WebKitNamespace = None

        WebKitPlaybackTargetAvailabilityEvent = None

        WebKitPoint = None

        WebKitTransitionEvent = None

        WebSocket = None

        WheelEvent = None

        Window = None

        Worker = None

        Worklet = None

        WritableStream = None

        WritableStreamDefaultController = None

        WritableStreamDefaultWriter = None

        XMLDocument = None

        XMLHttpRequest = None

        XMLHttpRequestEventTarget = None

        XMLHttpRequestProgressEvent = None

        XMLHttpRequestUpload = None

        XMLSerializer = None

        XPathEvaluator = None

        XPathExpression = None

        XPathResult = None

        XSLTProcessor = None

        __defineGetter__ = None

        __defineSetter__ = None

        __lookupGetter__ = None

        __lookupSetter__ = None

        _free = None

        _return_object = None

        _run = None

        addEventListener = None

        alert = None

        atob = None

        blur = None

        btoa = None

        cancelAnimationFrame = None

        captureEvents = None

        clearInterval = None

        clearTimeout = None

        close = None

        confirm = None

        createImageBitmap = None

        decodeURI = None

        decodeURIComponent = None

        dispatchEvent = None

        encodeURI = None

        encodeURIComponent = None

        escape = None

        eval = None

        fetch = None

        find = None

        focus = None

        getAttribute = None

        getComputedStyle = None

        getMatchedCSSRules = None

        getSelection = None

        hasOwnProperty = None

        isFinite = None

        isNaN = None

        isPrototypeOf = None

        makeid = None

        matchMedia = None

        moveBy = None

        moveTo = None

        open = None

        parseFloat = None

        parseInt = None

        postMessage = None

        print = None

        prompt = None

        propertyIsEnumerable = None

        queueMicrotask = None

        releaseEvents = None

        removeEventListener = None

        requestAnimationFrame = None

        resizeBy = None

        resizeTo = None

        scroll = None

        scrollBy = None

        scrollTo = None

        setInterval = None

        setTimeout = None

        stop = None

        toLocaleString = None

        toString = None

        unescape = None

        valueOf = None

        webkitCancelAnimationFrame = None

        webkitCancelRequestAnimationFrame = None

        webkitConvertPointFromNodeToPage = None

        webkitConvertPointFromPageToNode = None

        webkitRequestAnimationFrame = None

        webkitSpeechRecognition = None

        webkitURL = None

