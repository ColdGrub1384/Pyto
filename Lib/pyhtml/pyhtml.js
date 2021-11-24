_object_holder = {
  "window": window
};

_parents_holder = {
};

function makeid(length) {
    var result           = '';
    var characters       = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
    var charactersLength = characters.length;
    for ( var i = 0; i < length; i++ ) {
      result += characters.charAt(Math.floor(Math.random() * 
 charactersLength));
   }
   return result;
}

function getAttribute(object, name) {
    try {
        var attr = _object_holder[object][name];
    } catch (e) {
        console.log(Object.entries(_object_holder), object, name);
        throw e;
    }
    
    var id = _return_object(attr);
    _parents_holder[id] = _object_holder[object];
    return id;
}

function _return_object(object) {
    if (object === null) {
        return "";
    }

    for (key of Object.keys(_object_holder)) {
        var instance = _object_holder[key];
        if (instance === object) {
            return key;
        }
    }

    var id = makeid(5);

    info = [(typeof object), Array.isArray(object)];

    if (info[0] == "object") {
        info.push(null);
    } else {
        info.push(object);
    }

    if (info[1]) {
        try {
            info.push(JSON.stringify(object));
        } catch {
        }
    }

    id = id+";;"+btoa(unescape(encodeURIComponent(JSON.stringify(info))));

    _object_holder[id] = object;
    return id;
}

function _free_list(ids) {
    for (const id of ids) {
        _free(id);
    }
}

function _free(object) {

    if (object == "window") {
	    return;
    }

    delete _object_holder[object];
    delete _parents_holder[object];
}

function _run(python) {
    window.webkit.messageHandlers.webView.postMessage({ run: python });
}

const python = _run;

var _codeToRun = [];

var _executedScripts = [];

var _objects_with_pyon = [];

function _runScripts() {
    for (const script of document.querySelectorAll("script[type*='python']")) {

        var _break = false;
        for (const _script of _executedScripts) {
            if (_script === script) {
                _break = true;
                break;
            }
        }
        
        if (_break) {
            break;
        }
        
        if (script.src !== null && script.src !== undefined && script.src != "") {
            var xmlhttp = new XMLHttpRequest();
            xmlhttp.open("GET",script.src,false);
            xmlhttp.send();
            if (xmlhttp.readyState==4) {
                _executedScripts.push(script);
                _codeToRun.push(xmlhttp.responseText);
            }
        } else {
            _executedScripts.push(script);
            _codeToRun.push(script.innerHTML);
        }
    }

    _run(_codeToRun);
    _codeToRun = [];
}

function _pyon_triggered(event) {
    for (const object of _objects_with_pyon) {
        if (event.target === object) {
            for (const attr of object.attributes) {
                if (attr.nodeName.startsWith("pyon")) {
                    var name = attr.nodeName.split("pyon")[1];
                    if (name == event.type) {
                        _run(event.target.getAttribute("pyon"+event.type));
                    }
                }
            }
        }
    }
}

function _setAttributes() {
    
    var filterAttr = function(element) {
      return Array.prototype.some.call(
        element.attributes,
        function(attr) {
          return attr.nodeName.indexOf("pyon") === 0;
        }
      ) ? NodeFilter.FILTER_ACCEPT : NodeFilter.FILTER_SKIP;
    };
    filterAttr.acceptNode = filterAttr;

    var treeWalker = document.createTreeWalker(
      document.body,
      NodeFilter.SHOW_ELEMENT,
      filterAttr,
      false
    );
    var nodeList = [];
    while (treeWalker.nextNode()) {
      nodeList.push(treeWalker.currentNode);
    }
    
    _objects_with_pyon = nodeList;
        
    for (const event of Object.keys(window).filter(function (key) { return key.startsWith("on"); })) {
        window.removeEventListener(event.substring(2), _pyon_triggered);
        window.addEventListener(event.substring(2), _pyon_triggered);
    }
}

// TODO: Sometime doesn't run without the timeout
setTimeout(50, function () {
    _setAttributes();
    _runScripts();
});

var _observeDOM = (function() {
  var MutationObserver = window.MutationObserver || window.WebKitMutationObserver;

  return function( obj, callback ){
    if( !obj || obj.nodeType !== 1 ) return;

    if( MutationObserver ){
      // define a new observer
      var mutationObserver = new MutationObserver(callback)

      // have the observer observe foo for changes in children
      mutationObserver.observe( obj, { childList:true, subtree:true })
      return mutationObserver
    }
    
    // browser support fallback
    else if( window.addEventListener ){
      obj.addEventListener('DOMNodeInserted', callback, false)
      obj.addEventListener('DOMNodeRemoved', callback, false)
      obj.addEventListener('DOMAttrModified', callback, false)
        
    }
  }
})()

_observeDOM(document.getElementsByTagName("html")[0], function(m){
    _runScripts();
    _setAttributes();
});

document.head.innerHTML += `<meta name="viewport" content="width=device-width, initial-scale=1.0">`;
document.head.innerHTML += `<meta name="color-scheme" content="dark light">`;
document.body.style.fontFamily = "-apple-system";

true