﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:2.0.50727.42
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace Denisenko.Cutting.CutOptima.Properties {
    using System;
    
    
    /// <summary>
    ///   A strongly-typed resource class, for looking up localized strings, etc.
    /// </summary>
    // This class was auto-generated by the StronglyTypedResourceBuilder
    // class via a tool like ResGen or Visual Studio.
    // To add or remove a member, edit your .ResX file then rerun ResGen
    // with the /str option, or rebuild your VS project.
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Resources.Tools.StronglyTypedResourceBuilder", "2.0.0.0")]
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
    [global::System.Runtime.CompilerServices.CompilerGeneratedAttribute()]
    internal class Resources {
        
        private static global::System.Resources.ResourceManager resourceMan;
        
        private static global::System.Globalization.CultureInfo resourceCulture;
        
        [global::System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")]
        internal Resources() {
        }
        
        /// <summary>
        ///   Returns the cached ResourceManager instance used by this class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Resources.ResourceManager ResourceManager {
            get {
                if (object.ReferenceEquals(resourceMan, null)) {
                    global::System.Resources.ResourceManager temp = new global::System.Resources.ResourceManager("Denisenko.Cutting.CutOptima.Properties.Resources", typeof(Resources).Assembly);
                    resourceMan = temp;
                }
                return resourceMan;
            }
        }
        
        /// <summary>
        ///   Overrides the current thread's CurrentUICulture property for all
        ///   resource lookups using this strongly typed resource class.
        /// </summary>
        [global::System.ComponentModel.EditorBrowsableAttribute(global::System.ComponentModel.EditorBrowsableState.Advanced)]
        internal static global::System.Globalization.CultureInfo Culture {
            get {
                return resourceCulture;
            }
            set {
                resourceCulture = value;
            }
        }
        
        /// <summary>
        ///   Looks up a localized string similar to USE [master]
        ///GO
        ///CREATE DATABASE [CutOptima] ON  PRIMARY 
        ///( NAME = N&apos;CutOptima&apos;, FILENAME = N&apos;E:\Program Files\Microsoft SQL Server\MSSQL$V2000\data\CutOptima.mdf&apos; , SIZE = 896KB , MAXSIZE = UNLIMITED, FILEGROWTH = 10%)
        /// LOG ON 
        ///( NAME = N&apos;CutOptima_log&apos;, FILENAME = N&apos;E:\Program Files\Microsoft SQL Server\MSSQL$V2000\data\CutOptima_log.LDF&apos; , SIZE = 768KB , MAXSIZE = UNLIMITED, FILEGROWTH = 10%)
        /// COLLATE Cyrillic_General_CI_AS
        ///GO
        ///EXEC dbo.sp_dbcmptlevel @dbname=N&apos;CutOptima&apos;, @new_cmptlevel=80 -- SQL  [rest of string was truncated]&quot;;.
        /// </summary>
        internal static string CreateDB {
            get {
                return ResourceManager.GetString("CreateDB", resourceCulture);
            }
        }
    }
}