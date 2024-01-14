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

  const script = await fetch(url, {
    cache: "no-store",
  });

  eval(await script.text());

  const load = Module.cwrap("mpp_load");
  const a = Module.cwrap("mpp_client_a", undefined, [
    "string",
    "string",
    "string",
    "string",
    "number",
  ]);

  Module.onRuntimeInitialized = () => {
    load();

    MPP.client.on("a", (msg) => {
      a(msg.p._id, msg.p.name, msg.p.color, msg.a, msg.t);
    });
  };
}

globalThis.loadModule = loadModule;
loadModule("https://home.hri7566.info/mpp-wasm.js");
