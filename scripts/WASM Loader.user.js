// ==UserScript==
// @name        WASM Loader
// @namespace   Violentmonkey Scripts
// @match       https://multiplayerpiano.net/*
// @grant       none
// @version     1.0
// @author      Hri7566
// @description 1/13/2024, 1:39:32 AM
// ==/UserScript==

/**
 * Load a WASM module
 * @param {string} url URL to JS loader file from emcc
 */
async function loadModule(url) {
  const wasmUrl = url.substring(0, url.length - ".js".length) + ".wasm";

  var Module = {
    locateFile() {
      return wasmUrl;
    },
  };

  const script = await fetch(url);

  eval(await script.text());
  const load = Module.cwrap("mpp_load");

  Module.onRuntimeInitialized = () => {
    console.log(load());
  };
}

globalThis.loadModule = loadModule;
